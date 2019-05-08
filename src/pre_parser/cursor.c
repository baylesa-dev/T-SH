/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** cursor
*/

#include "preparser.h"

int	cursor_left(t_prmpt *prmpt)
{
  if (prmpt->pos < 1)
    return (1);
  prmpt->pos--;
  write(1, "\033[D", my_strlen("\033[D"));
  return (0);
}

int	cursor_right(t_prmpt *prmpt)
{
  if (prmpt->pos >= prmpt->max_p)
    return (1);
  prmpt->pos++;
  write(1, "\033[C", my_strlen("\033[C"));
  return (0);
}
