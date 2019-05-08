/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** my_get_nbr
*/

#include "my.h"

int	my_get_nbr(char *str)
{
  int	nb;
  int	i;
  int	sign;

  sign = 0;
  nb = 0;
  i = 0;
  if (str[0] == '-')
    {
      sign = 1;
      i = i + 1;
    }
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      nb = nb + str[i] - 48;
      if (str[i + 1] >= '0' && str[i + 1] <= '9')
	nb = nb * 10;
      i = i + 1;
    }
  if (sign)
    nb = -nb;
  return (nb);
}
