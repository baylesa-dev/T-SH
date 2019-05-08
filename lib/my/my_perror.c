/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** my_perror
*/

#include "my.h"
#include <unistd.h>

void	my_perror(char *str)
{
  write(2, str, my_strlen(str));
}
