/*
** get_path.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src
** 
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
** 
** Started on  Fri May  5 18:50:34 2017 Varé Paul
** Last update Sun May 21 17:18:45 2017 Alexandre CAUSSADE
*/

#include "mysh.h"
#include <stdlib.h>

int	my_envcmp(char *env, char *cmp)
{
  int   i;

  i = 0;
  while (env[i] != '=')
    {
      if (cmp[i] != env[i])
        return (0);
      i = i + 1;
    }
  return (1);
}

int	find_var_env(char **env, char *cmp)
{
  int   i;

  i = 0;
  while (env[i])
    {
      if (my_envcmp(env[i], cmp))
        return (i);
      i = i + 1;
    }
  return (-1);
}

int	count_path(char *env, int i)
{
  int   ret;

  ret = 0;
  while (env[i] && env[i] != ':')
    {
      i = i + 1;
      ret = ret + 1;
    }
  return (ret);
}

char	*parse_path(int *i, char *env)
{
  char  *ret;
  int   len;
  int   j;

  ret = NULL;
  len = count_path(env, *i);
  if (len > 0)
    {
      ret = (char *)malloc(sizeof(char) * (len + 1));
      if (ret == NULL)
        return (NULL);
      j = 0;
      while (env[*i] && env[*i] != ':')
        {
          ret[j] = env[*i];
          *i = *i + 1;
          j = j + 1;
	}
      ret[j] = '\0';
    }
  if (env[*i] == ':')
    *i = *i + 1;
  return (ret);
}

t_list		*get_path(char **env)
{
  t_list        *ret;
  int           i;
  char          *tmp;
  int           index;

  i = 5;
  ret = NULL;
  if ((index = find_var_env(env, "PATH")) != -1)
    {
      while (env[index][i])
        {
          tmp = parse_path(&i, env[index]);
          if (tmp && my_strcmp(tmp, "/"))
	    list_insert_front(&ret, tmp);
	}
    }
  return (ret);
}
