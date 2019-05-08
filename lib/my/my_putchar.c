/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** my_putchar
*/

#include "my.h"
#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
