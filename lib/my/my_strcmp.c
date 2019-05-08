/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** my_strcmp
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  if (!s1 || !s2)
    return (1);
  if (my_strlen(s1) > my_strlen(s2))
    return (1);
  if (my_strlen(s2) > my_strlen(s1))
    return (-1);
  i = 0;
  while (s1[i])
    {
      if (s1[i] > s2[i])
	return (1);
      if (s2[i] > s1[i])
	return (-1);
      i = i + 1;
    }
  return (0);
}
