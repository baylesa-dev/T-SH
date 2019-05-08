/*
** clean.c for clean in /home/adrien.bayles/Epitech/PSU_2016_42sh/src/pre_parser
** 
** Made by Adrien Bayles
** Login   <adrien.bayles@epitech.net>
** 
** Started on  Sun May 21 13:38:21 2017 Adrien Bayles
** Last update Sun May 21 13:38:22 2017 Adrien Bayles
*/

#include "preparser.h"

int	replace_cursor(t_prmpt *prmpt)
{
  int	i;

  i = prmpt->max_p;
  while (i > prmpt->pos)
    {
      write(1, "\033[D", my_strlen("\033[D"));
      i--;
    }
  return (0);
}

int	clean_line(t_prmpt *prmpt)
{
  int	i;

  i = prmpt->pos;
  if (prmpt->pos < 0)
    return (0);
  while (i < prmpt->max_p)
    {
      write(1, "\033[C", my_strlen("\033[C"));
      i++;
    }
  while (i > 0)
    {
      write(1, "\b \b", 3);
      i--;
    }
  return (0);
}

int	clear_screen(t_prmpt *prmpt)
{
  write(1, "\e[1;1H\e[2J", my_strlen("\e[1;1H\e[2J"));
  prompt();
  write(1, prmpt->cmd, my_strlen(prmpt->cmd));
  prmpt->max_p = my_strlen(prmpt->cmd);
  return (0);
}
