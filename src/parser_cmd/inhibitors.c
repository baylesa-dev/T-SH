/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** inhibitors
*/

#include "mysh.h"
#include "parser_cmd.h"
#include <stdlib.h>

int	detect_inhibitors(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\\')
	return (1);
      i = i + 1;
    }
  return (0);
}

int	my_inhibitorslen(char *str)
{
  int	i;
  int	ct;

  ct = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] != '\\' || (str[i] == '\\' && i > 0 && str[i - 1] == '\\'))
	ct = ct + 1;
      i = i + 1;
    }
  return (ct);
}

char	*delete_inhibitors(char *str)
{
  char	*ret;
  int	i;
  int	j;

  ret = (char *)malloc(sizeof(char) * (my_inhibitorslen(str) + 1));
  if (!ret)
    return (NULL);
  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] != '\\' || (str[i] == '\\' && i > 0 && str[i - 1] == '\\'))
	{
	  ret[j] = str[i];
	  j = j + 1;
	}
      i = i + 1;
    }
  ret[j] = '\0';
  return (ret);
}

int	inhibitors(char **tab)
{
  char	*tmp;
  int	i;

  i = 0;
  while (tab[i])
    {
      if (detect_inhibitors(tab[i]))
	{
	  tmp = delete_inhibitors(tab[i]);
	  if (!tmp)
	    return (1);
	  free(tab[i]);
	  tab[i] = tmp;
	}
      i = i + 1;
    }
  return (0);
}
