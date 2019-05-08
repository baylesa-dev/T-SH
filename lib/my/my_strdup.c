/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** my_strdup
*/

#include "my.h"
#include <stdlib.h>

char	*my_strdup(char *str)
{
  char	*ret;
  int	i;

  ret = (char *)malloc(sizeof(char) * (my_strlen(str) + 1));
  if (!ret)
    return (NULL);
  i = 0;
  while (str[i])
    {
      ret[i] = str[i];
      i = i + 1;
    }
  ret[i] = '\0';
  return (ret);
}
