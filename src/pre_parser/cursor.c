/*
** cursor.c for cursor in /home/adrien.bayles/Epitech/PSU_2016_42sh/src/pre_parser
** 
** Made by Adrien Bayles
** Login   <adrien.bayles@epitech.net>
** 
** Started on  Sun May 21 13:38:43 2017 Adrien Bayles
** Last update Sun May 21 14:01:56 2017 Adrien Bayles
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
