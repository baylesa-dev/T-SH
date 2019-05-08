/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** my_dollarconcat
*/

#include "mysh.h"
#include "builtin.h"
#include <stdlib.h>

int	my_dollarlen(char *str)
{
  int   i;

  if (!str)
    return (0);
  i = 0;
  while (str[i] && str[i] != '$')
    i = i + 1;
  return (i);
}

char	*my_dollarconcat(char *s1, char *s2)
{
  char	*ret;
  int   i;
  int   j;

  ret = (char *)malloc(sizeof(char) * (my_strlen(s1) + my_dollarlen(s2) + 1));
  if (!ret)
    return (NULL);
  i = 0;
  j = 0;
  while (s1 && s1[i])
    {
      ret[j] = s1[i];
      i = i + 1;
      j = j + 1;
    }
  i = 0;
  while (i < my_dollarlen(s2))
    {
      ret[j] = s2[i];
      i = i + 1;
      j = j + 1;
    }
  ret[j] = '\0';
  (s1 ? free(s1) : 0);
  return (ret);
}
