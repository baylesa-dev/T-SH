/*
** redirections_left_pipe.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src/pipe
**
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
**
** Started on  Thu May 11 23:56:46 2017 Varé Paul
** Last update Sun May 21 15:14:19 2017 Adrien Bayles
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

int	g_one_chevron_pipe(t_table *s_table, char ***env, int pipefd[2])
{
  int   fd;
  int   pid;
  char	**tab;

  if (!(tab = my_str_to_wordtab(s_table->output)))
    return (1);
  errno = 0;
  if ((fd = open(s_table->input, O_RDONLY)) == -1)
    return (check_error_fd(errno, s_table->input));
  pid = fork();
  if (pid == -1)
    return (1);
  if (pid == 0)
    {
      dup2(fd, 0);
      close(pipefd[0]);
      dup2(pipefd[1], 1);
      close(pipefd[1]);
      exit(exec_for_pipe(tab, env, s_table->output));
    }
  else
    s_table->pid = pid;
  free_tab(tab);
  return (0);
}

int	read_line_on_pipe(t_table *s_table, char ***env,
			  int pipefd[2], int pipefd2[2])
{
  int   pid;
  char	**tab;

  if (!(tab = my_str_to_wordtab(s_table->output)))
    return (1);
  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
    {
      close(pipefd[1]);
      dup2(pipefd[0], 0);
      close(pipefd[0]);
      close(pipefd2[0]);
      dup2(pipefd2[1], 1);
      close(pipefd2[1]);
      exit(exec_for_pipe(tab, env, s_table->output));
    }
  else
    {
      close(pipefd[0]);
      close(pipefd[1]);
      s_table->pid = pid;
    }
  free_tab(tab);
  return (0);
}

int	g_double_chevron_pipe(t_table *s_table, char ***env, int pipefd2[2])
{
  int   pid;
  int	pipefd[2];

  if (pipe(pipefd) == -1)
    return (1);
  pid = fork();
  if (pid == -1)
    return (1);
  if (pid == 0)
    exit(write_line_pipe(s_table->input, pipefd));
  else
    wait(NULL);
  return (read_line_on_pipe(s_table, env, pipefd, pipefd2));
}
