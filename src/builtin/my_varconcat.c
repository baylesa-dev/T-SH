/*
** my_varconcat.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src/builtin
**
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
**
** Started on  Thu May 18 11:12:25 2017 Varé Paul
** Last update Sun May 21 17:11:45 2017 Varé Paul
*/

#include "mysh.h"
#include "builtin.h"
#include <stdlib.h>
#include <unistd.h>

int	my_varcmp(char *var, char *env)
{
  int	i;

  i = 0;
  if (!var[i + 1] || var[i + 1] == '$' ||
      var[i + 1] == ' ' || var[i + 1] == '\t')
    return (1);
  while (var[i] && var[i] != '$' && var[i] != ' ' && var[i] != '\t')
    {
      if (!env[i] || env[i] != var[i])
	return (1);
      i = i + 1;
    }
  return (0);
}

char	*find_dollar_env(char *to_find, char **env)
{
  int	i;
  int	j;

  i = 0;
  while (env[i])
    {
      if (my_varcmp(to_find, env[i]) == 0)
	{
	  j = 0;
	  while (env[i][j] && env[i][j] != '=')
	    j = j + 1;
	  return (&env[i][j + 1]);
	}
      i = i + 1;
    }
  return (NULL);
}

int	add_dollar_var(char *str, char **env, int *i, char **ret)
{
  char	*tmp;

  if ((tmp = find_dollar_env(&str[*i + 1], env)))
    {
      if (!(*ret = my_strconcat(*ret, tmp)))
	return (0);
    }
  *i = *i + 1;
  while (str[*i] && str[*i] != '$' && str[*i] != ' ' && str[*i] != '\t')
    *i = *i + 1;
  return (0);
}

char	*my_varconcat(char *str, char **env)
{
  char	*ret;
  int	i;

  ret = NULL;
  i = 0;
  while (str[i])
    {
      if (str[i] != '$')
	{
	  if (!(ret = my_dollarconcat(ret, &str[i])))
	    return (0);
	  while (str[i] && str[i] != '$')
	    i = i + 1;
	}
      else if (str[i + 1] && str[i + 1] != ' ' &&
	       str[i + 1] != '\t' && str[i + 1] != '$')
	add_dollar_var(str, env, &i, &ret);
      else
	{
	  if (!(ret = my_strconcat(ret, "$")))
	    return (0);
	  i = i + 1;
	}
    }
  return (ret);
}
