/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** swap_ptr
*/

#include "mysh.h"
#include "pipe.h"

void	swap_ptr(char **p1, char **p2)
{
  char  *tmp;

  tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

