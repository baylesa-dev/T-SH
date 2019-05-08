/*
** redirections.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src/pipe
** 
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
** 
** Started on  Wed May 10 15:45:17 2017 Varé Paul
** Last update Sun May 21 15:13:17 2017 Adrien Bayles
*/

#include "mysh.h"
#include "pipe.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <wait.h>

int	check_error_fd(int code, char *name)
{
  if (code == 2)
    {
      my_perror(name);
      my_perror(": No such file or directory.\n");
    }
  if (code == 13)
    {
      my_perror(name);
      my_perror(": Permission denied.\n");
    }
  return (1);
}

int	g_one_chevron(char **cmd, char *name, char ***env, t_table *table)
{
  int   fd;
  int   pid;
  int   status;

  errno = 0;
  if ((fd = open(name, O_RDONLY)) == -1)
    return (check_error_fd(errno, name));
  pid = fork();
  if (pid == -1)
    return (1);
  if (pid == 0)
    {
      if (dup2(fd, 0) == -1)
	exit(1);
      exit(exec_for_pipe(cmd, env, table->input));
    }
  else
    {
      waitpid(pid, &status, 0);
      if (WIFEXITED(status))
        status = WEXITSTATUS(status);
      else if (WIFSIGNALED(status))
        status = sig_term(status);
    }
  return (status);
}

int	write_line_pipe(char *name, int pipefd[2])
{
  char  *str;
  char	*tmp;

  tmp = NULL;
  str = NULL;
  close(pipefd[0]);
  while (my_strcmp(str, name))
    {
      if (tmp)
	free(tmp);
      if (isatty(0))
        my_printf("? ");
      str = get_next_line(0);
      if (str == NULL)
        exit(0);
      if (my_strcmp(str, name))
        {
          write(pipefd[1], str, my_strlen(str));
          write(pipefd[1], "\n", 1);
	}
      tmp = str;
    }
  free(tmp);
  close(pipefd[1]);
  return (0);
}

int	read_line_pipe(char **cmd, char ***env, int pipefd[2], t_table *table)
{
  int   pid;
  int   status;

  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
    {
      close(pipefd[1]);
      if (dup2(pipefd[0], 0) == -1)
	exit(1);
      close(pipefd[0]);
      exit(exec_for_pipe(cmd, env, table->input));
    }
  else
    {
      close(pipefd[0]);
      close(pipefd[1]);
      waitpid(pid, &status, 0);
      if (WIFEXITED(status))
        status = WEXITSTATUS(status);
      else if (WIFSIGNALED(status))
	status = sig_term(status);
    }
  return (status);
}

int	g_double_chevron(char **cmd, char *name, char ***env, t_table *table)
{
  int   pid;
  int   pipefd[2];

  if (pipe(pipefd) == -1)
    return (1);
  pid = fork();
  if (pid == -1)
    return (1);
  if (pid == 0)
    exit(write_line_pipe(name, pipefd));
  else
    wait(NULL);
  return (read_line_pipe(cmd, env, pipefd, table));
}
