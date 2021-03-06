/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** redirections_right
*/

#include "mysh.h"
#include "pipe.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <wait.h>
#include <stdlib.h>

int	d_one_chevron(char **cmd, char *name, char ***env, t_table *table)
{
  int   fd;
  int   pid;
  int   status;

  fd = open(name, O_CREAT | O_RDWR, 0644);
  if (fd == -1)
    return (1);
  pid = fork();
  if (pid == -1)
    return (1);
  if (pid == 0)
    {
      if (dup2(fd, 1) == -1)
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

int	d_double_chevron(char **cmd, char *name, char ***env, t_table *table)
{
  int   fd;
  int   pid;
  int   status;

  fd = open(name, O_CREAT | O_RDWR | O_APPEND, 0644);
  if (fd == -1)
    return (1);
  pid = fork();
  if (pid == -1)
    return (1);
  if (pid == 0)
    {
      if (dup2(fd, 1) == -1)
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
