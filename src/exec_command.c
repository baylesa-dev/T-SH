/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** exec_command
*/

#include "mysh.h"
#include <errno.h>
#include <wait.h>
#include <stdlib.h>
#include <unistd.h>

int	check_errno(int code, char *str)
{
  if (code == 8)
    {
      my_perror(str);
      my_perror(": Exec format error. Binary file not executable.\n");
      exit(1);
    }
  if (code == 13)
    {
      my_perror(str);
      my_perror(": Permission denied.\n");
      exit(1);
    }
  return (0);
}

void	default_path(t_list **path)
{
  char	*tmp;

  if (!*path)
    {
      tmp = my_strdup("/usr/bin");
      list_insert_front(path, tmp);
      tmp = my_strdup("/bin");
      list_insert_front(path, tmp);
      tmp = my_strdup("/bin/user");
      list_insert_front(path, tmp);
    }
}

int	process_child(t_list *path, char **tab, char **env)
{
  char	*tmp;

  errno = 0;
  default_path(&path);
  execve(tab[0], tab, env);
  check_errno(errno, tab[0]);
  if (tab[0][0] != '.' && tab[0][0] != '/')
    {
      while (path)
	{
	  tmp = my_pathconcat((char *)path->data, tab[0]);
	  if (tmp)
	    {
	      execve(tmp, tab, env);
	      free(tmp);
	    }
	  path = path->next;
	}
    }
  my_perror(tab[0]);
  my_perror(": Command not found.\n");
  exit(1);
}

int	sig_term(int status)
{
  if (WTERMSIG(status) == 11)
    {
      if (WCOREDUMP(status))
        my_perror("Segmentation fault (core dumped)\n");
      else
        my_perror("Segmentation fault\n");
      return (139);
    }
  if (WTERMSIG(status) == 8)
    {
      if (WCOREDUMP(status))
        my_perror("Floating exception (core dumped)\n");
      else
        my_perror("Floating exception\n");
      return (136);
    }
  return (1);
}

int		exec_command(char **tab, char **env)
{
  t_list        *path;
  t_list	*save;
  int           pid;
  int           status;
  int           ret;

  ret = 0;
  path = get_path(env);
  save = path;
  pid = fork();
  if (pid == -1)
    return (84);
  if (pid == 0)
    process_child(path, tab, env);
  else
    {
      waitpid(pid, &status, 0);
      if (WIFEXITED(status))
        ret = WEXITSTATUS(status);
      else if (WIFSIGNALED(status))
	ret = sig_term(status);
    }
  free_list(save);
  return (ret);
}
