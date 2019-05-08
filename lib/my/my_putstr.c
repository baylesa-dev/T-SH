/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** my_putstr
*/

#include "my.h"
#include <unistd.h>

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
