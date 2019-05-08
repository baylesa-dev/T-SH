/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** redirections_right_pipe
*/

#include "mysh.h"
#include "pipe.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int	d_one_chevron_pipe(t_table *s_table, char ***env, int pipefd[2])
{
  int   fd;
  int   pid;
  char	**tab;

  if (!(tab = my_str_to_wordtab(s_table->input)))
    return (1);
  fd = open(s_table->output, O_CREAT | O_RDWR, 0644);
  if (fd == -1)
    return (1);
  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
    {
      dup2(fd, 1);
      close(pipefd[1]);
      dup2(pipefd[0], 0);
      close(pipefd[0]);
      exit(exec_for_pipe(tab, env, s_table->input));
    }
  else
    s_table->pid = pid;
  close(pipefd[0]);
  close(pipefd[1]);
  free_tab(tab);
  return (0);
}

int	d_one_chevron_out(t_table *s_table, int pipefd[2])
{
  int   fd;
  int   pid;
  char	*str;

  fd = open(s_table->output, O_CREAT | O_RDWR, 0644);
  if (fd == -1)
    return (1);
  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
    {
      close(pipefd[1]);
      while ((str = get_next_line(pipefd[0])))
	{
	  write(fd, str, my_strlen(str));
	  write(fd, "\n", 1);
	  free(str);
	}
      exit(0);
    }
  else
    s_table->pid = pid;
  close(pipefd[0]);
  close(pipefd[1]);
  return (0);
}

int	d_double_chevron_pipe(t_table *s_table, char ***env, int pipefd[2])
{
  int   fd;
  int   pid;
  char  **tab;

  if (!(tab = my_str_to_wordtab(s_table->input)))
    return (1);
  fd = open(s_table->output, O_CREAT | O_RDWR | O_APPEND, 0644);
  if (fd == -1)
    return (1);
  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
    {
      dup2(fd, 1);
      close(pipefd[1]);
      dup2(pipefd[0], 0);
      close(pipefd[0]);
      exit(exec_for_pipe(tab, env, s_table->input));
    }
  else
    s_table->pid = pid;
  close(pipefd[0]);
  close(pipefd[1]);
  free_tab(tab);
  return (0);
}

int	d_double_chevron_out(t_table *s_table, int pipefd[2])
{
  int   fd;
  int   pid;
  char  *str;

  fd = open(s_table->output, O_CREAT | O_RDWR | O_APPEND, 0644);
  if (fd == -1)
    return (1);
  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
    {
      close(pipefd[1]);
      while ((str = get_next_line(pipefd[0])))
        {
          write(fd, str, my_strlen(str));
          write(fd, "\n", 1);
          free(str);
        }
      exit(0);
    }
  else
    s_table->pid = pid;
  close(pipefd[0]);
  close(pipefd[1]);
  return (0);
}
