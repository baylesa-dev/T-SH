/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** control
*/

#include "preparser.h"

int	control_d(t_prmpt *prmpt)
{
  write(1, "\n", 1);
  tcsetattr(0, TCSANOW, &prmpt->old_trm);
  free_all(prmpt);
  exit(0);
}

int	control_c(t_prmpt *prmpt)
{
  write(1, "\n", 1);
  prompt();
  prmpt->cmd = NULL;
  prmpt->pos = 0;
  prmpt->max_p = 0;
  return (0);
}

int	control_a(t_prmpt *prmpt)
{
  while (prmpt->pos > 0)
    {
      write(1, "\033[D", my_strlen("\033[D"));
      prmpt->pos--;
    }
  return (0);
}

int	control_k(t_prmpt *prmpt)
{
  int	i;

  i = 0;
  if (prmpt->cmd == NULL || prmpt->max_p == 0)
    return (1);
  prmpt->old_cmd = my_strdup(prmpt->cmd);
  free(prmpt->cmd);
  prmpt->cmd = malloc(sizeof(char) * (prmpt->max_p - prmpt->pos + 1));
  if (prmpt->cmd == NULL)
    return (84);
  prmpt->cmd[prmpt->pos] = '\0';
  while (i < prmpt->pos)
    {
      prmpt->cmd[i] = prmpt->old_cmd[i];
      i++;
    }
  erase_record(prmpt);
  if (i != 0)
    {
      write(1, prmpt->cmd, my_strlen(prmpt->cmd));
      prmpt->pos = my_strlen(prmpt->cmd);
      prmpt->max_p = my_strlen(prmpt->cmd);
    }
  return (0);
}
