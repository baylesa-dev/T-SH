/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** get_output
*/

#include "mysh.h"
#include "pipe.h"
#include <stdlib.h>

int	my_baselen(char *str)
{
  int   i;

  i = 0;
  while (str[i] && str[i] != '<' && str[i] != '>')
    i = i + 1;
  return (i);
}

void	path_output(char *str, int *i)
{
  while (str[*i] && str[*i] != '<' && str[*i] != '>')
    *i = *i + 1;
  if ((str[*i] == '>' && str[*i + 1] == '>') ||
      (str[*i] == '<' && str[*i + 1] == '<'))
    *i = *i + 1;
  *i = *i + 1;
  while (str[*i] == ' ' || str[*i] == '\t')
    *i = *i + 1;
  while (str[*i] && str[*i] != ' ' && str[*i] != '\t')
    *i = *i + 1;
}

char	*get_output_argv(char *str)
{
  int   i;
  int   j;
  char  *ret;

  i = 0;
  path_output(str, &i);
  if (!(ret = (char *)malloc(sizeof(char) * (my_strlen(&str[i]) + 1))))
    return (NULL);
  j = 0;
  while (str[i])
    {
      ret[j] = str[i];
      i = i + 1;
      j = j + 1;
    }
  ret[j] = '\0';
  return (ret);
}

char	*get_ouput(char *str)
{
  char  *base;
  char  *ret;
  int   i;

  base = (char *)malloc(sizeof(char) * (my_baselen(str) + 1));
  if (!base)
    return (NULL);
  i = 0;
  while (str[i] && str[i] != '<' && str[i] != '>')
    {
      base[i] = str[i];
      i = i + 1;
    }
  base[i] = '\0';
  ret = get_output_argv(&str[i]);
  base = my_strconcat(base, ret);
  free(ret);
  return (base);
}
