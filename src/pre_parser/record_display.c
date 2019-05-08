/*
** record_display.c for record_display in /home/adrien.bayles/Epitech/PSU_2016_42sh/src/pre_parser
** 
** Made by Adrien Bayles
** Login   <adrien.bayles@epitech.net>
** 
** Started on  Sun May 21 13:39:33 2017 Adrien Bayles
** Last update Sun May 21 15:21:37 2017 Adrien Bayles
*/

#include "preparser.h"

int	clean_record(t_prmpt *prmpt)
{
  prmpt->pos = prmpt->max_p = 0;
  prmpt->cmd = NULL;
  prmpt->cmd = malloc(sizeof(char));
  prmpt->cmd[0] = '\0';
  return (0);
}

int	erase_record(t_prmpt *prmpt)
{
  int	i;

  i = prmpt->pos;
  while (prmpt->pos < prmpt->max_p)
    {
      write(1, "\033[C", my_strlen("\033[C"));
      prmpt->pos++;
    }
  while (prmpt->max_p > 0)
    {
      write(1, "\b \b", 3);
      prmpt->max_p--;
    }
  prmpt->pos = i;
  return (0);
}

int	record_down(t_prmpt *prmpt)
{
  int	i;
  t_rec	*cur;

  i = 0;
  if (prmpt->pos_rec < 0 || prmpt->len_rec == 0)
    return (1);
  cur = prmpt->rec_first;
  while (i++ < (prmpt->pos_rec - 1))
    cur = cur->next;
  erase_record(prmpt);
  if (prmpt->pos_rec - 1 > 0)
    {
      prmpt->cmd = cur->rec_cmd;
      write(1, prmpt->cmd, my_strlen(prmpt->cmd));
      prmpt->pos = my_strlen(prmpt->cmd);
      prmpt->max_p = my_strlen(prmpt->cmd);
      replace_cursor(prmpt);
    }
  else
    clean_record(prmpt);
  prmpt->pos_rec--;
  return (0);
}

int	record_up(t_prmpt *prmpt)
{
  int	i;
  t_rec	*cur;

  i = 0;
  cur = prmpt->rec_first;
  if (prmpt->pos_rec >= prmpt->len_rec)
    return (1);
  while (cur && i < prmpt->pos_rec)
    {
      cur = cur->next;
      i++;
    }
  clean_line(prmpt);
  prmpt->cmd = cur->rec_cmd;
  write(1, prmpt->cmd, my_strlen(prmpt->cmd));
  prmpt->pos = my_strlen(prmpt->cmd);
  prmpt->max_p = my_strlen(prmpt->cmd);
  replace_cursor(prmpt);
  prmpt->pos_rec++;
  return (0);
}
