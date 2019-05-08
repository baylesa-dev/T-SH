/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** my_strncmp
*/

#include "my.h"

int	my_strncmp(char	*s1, char *s2, int size)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && i < size)
    {
      if (s1[i] > s2[i])
	return (1);
      if (s1[i] < s2[i])
	return (-1);
      i = i + 1;
    }
  return (0);
}
