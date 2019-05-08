/*
** copy_env.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src
** 
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
** 
** Started on  Sat May  6 21:14:56 2017 Varé Paul
** Last update Sun May 21 17:16:01 2017 Alexandre CAUSSADE
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
