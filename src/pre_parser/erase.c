/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** erase
*/

#include "preparser.h"

int	display_delete(t_prmpt *prmpt)
{
  clean_line(prmpt);
  write(1, prmpt->cmd, my_strlen(prmpt->cmd));
  prmpt->max_p--;
  replace_cursor(prmpt);
  return (0);
}

int	delete_key(t_prmpt *prmpt)
{
  int	i;

  i = 0;
  if (prmpt->pos == prmpt->max_p || prmpt->cmd == NULL)
    return (1);
  prmpt->old_cmd = my_strdup(prmpt->cmd);
  free(prmpt->cmd);
  if ((prmpt->cmd = malloc(sizeof(char) * (prmpt->max_p))) == NULL)
    return (1);
  prmpt->cmd[prmpt->max_p - 1] = '\0';
  while (i < prmpt->pos)
    {
      prmpt->cmd[i] = prmpt->old_cmd[i];
      i++;
    }
  while (i < (prmpt->max_p - 1))
    {
      prmpt->cmd[i] = prmpt->old_cmd[i + 1];
      i++;
    }
  display_delete(prmpt);
  return (0);
}

int	hard_erase(t_prmpt *prmpt)
{
  int	i;

  i = 0;
  prmpt->old_cmd = my_strdup(prmpt->cmd);
  free(prmpt->cmd);
  prmpt->cmd = malloc(sizeof(char) * (prmpt->max_p));
  if (prmpt->cmd == NULL)
    return (1);
  prmpt->cmd[prmpt->max_p - 1] = '\0';
  while (i < (prmpt->pos - 1))
    {
      prmpt->cmd[i] = prmpt->old_cmd[i];
      i++;
    }
  while (i < (prmpt->max_p - 1))
   {
      prmpt->cmd[i] = prmpt->old_cmd[i + 1];
      i++;
    }
  return (0);
}

int	simple_erase(t_prmpt *prmpt)
{
  int	i;

  i = 0;
  prmpt->old_cmd = my_strdup(prmpt->cmd);
  free(prmpt->cmd);
  prmpt->cmd = malloc(sizeof(char) * (prmpt->max_p));
  if (prmpt->cmd == NULL)
    return (1);
  prmpt->cmd[prmpt->max_p - 1] = '\0';
  while (i < (prmpt->max_p - 1))
    {
      prmpt->cmd[i] = prmpt->old_cmd[i];
      i++;
    }
  return (0);
}

int	erase_char(t_prmpt *prmpt)
{
  if (prmpt->cmd == NULL || prmpt->pos < 1)
    return (1);
  if (prmpt->pos == prmpt->max_p)
    simple_erase(prmpt);
  else
    hard_erase(prmpt);
  clean_line(prmpt);
  write(1, prmpt->cmd, my_strlen(prmpt->cmd));
  prmpt->pos--;
  prmpt->max_p--;
  replace_cursor(prmpt);
  return (0);
}
