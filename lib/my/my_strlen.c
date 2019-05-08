/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** my_strlen
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  if (!str)
    return (0);
  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}
