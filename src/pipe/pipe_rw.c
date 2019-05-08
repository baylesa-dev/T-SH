/*
** pipe_rw.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src/pipe
** 
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
** 
** Started on  Wed May 10 14:44:05 2017 Varé Paul
** Last update Sun May 21 15:11:01 2017 Adrien Bayles
*/

#include "mysh.h"
#include "pipe.h"
#include <unistd.h>
#include <stdlib.h>

int	write_pipe(char *cmd, char ***env, int pipefd[2], pid_t *f_pid)
{
  pid_t pid;
  char	**tab;

  if (!(tab = my_str_to_wordtab(cmd)))
    return (1);
  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
    {
      close(pipefd[0]);
      if (dup2(pipefd[1], 1) == -1)
	exit(1);
      close(pipefd[1]);
      exit(exec_for_pipe(tab, env, cmd));
    }
  else
    *f_pid = pid;
  free_tab(tab);
  return (0);
}

void	pipe_child(int pipefd[2], int pipefd2[2])
{
  close(pipefd[1]);
  if (dup2(pipefd[0], 0) == -1)
    exit(1);
  close(pipefd[0]);
  close(pipefd2[0]);
  if (dup2(pipefd2[1], 1) == -1)
    exit(1);
  close(pipefd2[1]);
}

int	rw_pipe(t_table *table, char ***env, int pipefd[2], int pipefd2[2])
{
  pid_t pid;
  char	**tab;

  if (!(tab = my_str_to_wordtab(table->cmd)))
    return (1);
  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
    {
      pipe_child(pipefd, pipefd2);
      exit(exec_for_pipe(tab, env, table->cmd));
    }
  else
    {
      table->pid = pid;
      close(pipefd[1]);
      close(pipefd[0]);
    }
  free_tab(tab);
  return (0);
}

int	read_pipe(char *cmd, char ***env, int pipefd[2], pid_t *f_pid)
{
  pid_t pid;
  char	**tab;

  if (!(tab = my_str_to_wordtab(cmd)))
    return (1);
  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
    {
      close(pipefd[1]);
      if (dup2(pipefd[0], 0) == -1)
	exit(1);
      close(pipefd[0]);
      exit(exec_for_pipe(tab, env, cmd));
    }
  else
    {
      *f_pid = pid;
      close(pipefd[0]);
      close(pipefd[1]);
    }
  free_tab(tab);
  return (0);
}
