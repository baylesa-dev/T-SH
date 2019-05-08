/*
** cd.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src/builtin
**
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
**
** Started on  Sat May  6 21:34:44 2017 Varé Paul
** Last update Sun May 21 17:03:55 2017 Varé Paul
*/

#include "mysh.h"
#include "builtin.h"
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int	error_cd(char *path, int code)
{
  if (code == 2)
    {
      my_perror(path);
      my_perror(": No such file or directory.\n");
    }
  if (code == 20)
    {
      my_perror(path);
      my_perror(": Not a directory.\n");
    }
  if (code == 13)
    {
      my_perror(path);
      my_perror(": Permission denied.\n");
    }
  return (1);
}

char	*get_env_var(char **env, int index)
{
  int	i;

  i = 0;
  while (env[index][i] != '=')
    i = i + 1;
  return (&env[index][i + 1]);
}

int	cd_home(char **tab, char **env, char **prev, char *pwd)
{
  int	index;
  char	*path;

  if ((index = find_var_env(env, "HOME")) == -1)
    {
      if (!tab[1])
	my_perror("cd: No home directory.\n");
      if (tab[1] && my_strcmp(tab[1], "~"))
	my_perror("No $home variable set.\n");
      if (tab[1] && my_strcmp(tab[1], "home"))
	my_perror("home: No such file or directory.\n");
      return (1);
    }
  path = get_env_var(env, index);
  if (chdir(path) == -1)
    {
      my_perror("cd: Can't change to home directory.\n");
      return (1);
    }
  if (*prev)
    free(*prev);
  *prev = pwd;
  return (0);
}

int	cd_prev(char **prev, char *pwd)
{
  if (*prev == NULL)
    {
      my_perror(": No such file or directory.\n");
      return (1);
    }
  else
    {
      chdir(*prev);
      if (*prev)
	free(*prev);
      *prev = pwd;
    }
  return (0);
}

int		cd(char **tab, char ***env, char *cmd)
{
  static char	*prev = NULL;
  char		*pwd;

  (void)cmd;
  pwd = get_pwd();
  if (!tab[1])
    return (cd_home(tab, *env, &prev, pwd));
  if (tab[1] && tab[2])
    {
      my_perror("cd: Too many arguments.\n");
      return (1);
    }
  if (my_strcmp(tab[1], "~") == 0 || my_strcmp(tab[1], "home") == 0)
    return (cd_home(tab, *env, &prev, pwd));
  if (my_strcmp(tab[1], "-") == 0)
    return (cd_prev(&prev, pwd));
  errno = 0;
  if (chdir(tab[1]) == -1)
    return (error_cd(tab[1], errno));
  if (prev)
    free(prev);
  prev = pwd;
  return (0);
}
