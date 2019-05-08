/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** unsetenv
*/

#include "mysh.h"
#include "builtin.h"
#include <stdlib.h>

char	**sub_env(char **env, int index)
{
  char	**ret;
  int	i;
  int	j;

  ret = (char **)malloc(sizeof(char *) * (my_tablen(env) + 1));
  if (ret == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (env[i])
    {
      if (j == index)
	{
	  free(env[index]);
	  j = j + 1;
	}
      ret[i] = env[j];
      i = i + 1;
      j = j + 1;
    }
  ret[i] = 0;
  free(env);
  return (ret);
}

int	my_unsetenv(char **tab, char ***env, char *cmd)
{
  int	i;
  int	index;

  (void)cmd;
  if (!tab[1])
    {
      my_perror("unsetenv: Too few arguments.\n");
      return (1);
    }
  i = 0;
  while (tab[i])
    {
      if ((index = find_var_env(*env, tab[i])) != -1)
	*env = sub_env(*env, index);
      i = i + 1;
    }
  return (0);
}
