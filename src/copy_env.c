/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** copy_env
*/

#include "mysh.h"
#include "builtin.h"
#include <stdlib.h>

int	assign_env(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (0);
}

char	**cp_env(char **env)
{
  char	**ret;
  int	i;

  ret = (char **)malloc(sizeof(char *) * (my_tablen(env) + 1));
  if (ret == NULL)
    return (NULL);
  i = 0;
  while (env[i])
    {
      ret[i] = (char *)malloc(sizeof(char) * (my_strlen(env[i]) + 1));
      if (ret[i] == NULL)
	return (NULL);
      assign_env(ret[i], env[i]);
      i = i + 1;
    }
  ret[i] = 0;
  return (ret);
}
