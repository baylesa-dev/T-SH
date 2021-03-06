/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** my_spconcat
*/

#include "mysh.h"
#include <stdlib.h>

int	assign_n(char *dest, char *src, int i)
{
  int	j;

  if (src)
    {
      j = 0;
      while (src[j] != '\0')
	{
	  dest[i] = src[j];
	  i = i + 1;
	  j = j + 1;
	}
      dest[i] = '\0';
    }
  return (0);
}

char	*my_envconcat(char *s1, char *s2)
{
  char	*ret;
  int	i;

  ret = (char *)malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 2));
  if (ret == NULL)
    return (NULL);
  i = 0;
  while (s1[i] != '\0')
    {
      ret[i] = s1[i];
      i = i + 1;
    }
  ret[i] = '=';
  i = i + 1;
  assign_n(ret, s2, i);
  return (ret);
}

char	*my_pathconcat(char *s1, char *s2)
{
  char  *ret;
  int   i;

  ret = (char *)malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 2));
  if (ret == NULL)
    return (NULL);
  i = 0;
  while (s1[i] != '\0')
    {
      ret[i] = s1[i];
      i = i + 1;
    }
  if (s1[i - 1] != '/')
    {
      ret[i] = '/';
      i = i + 1;
    }
  assign_n(ret, s2, i);
  return (ret);
}
