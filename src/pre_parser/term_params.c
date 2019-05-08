/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** term_params
*/

#include "preparser.h"

int	reinit_prompt(t_prmpt *prmpt)
{
  prmpt->pos = 0;
  prmpt->max_p = 0;
  if (prmpt->cmd)
    {
      prmpt->old_cmd = my_strdup(prmpt->cmd);
      free(prmpt->cmd);
    }
  prmpt->cmd = malloc(sizeof(char));
  prmpt->cmd[0] = '\0';
  return (0);
}

int	term_params(struct termios *old, struct termios *new)
{
  if ((tcgetattr(0, old)) != 0)
    return (1);
  *new = *old;
  (*new).c_lflag &= ~(ICANON | ECHO | ECHOK | ECHONL | ISIG);
  if ((tcsetattr(0, TCSANOW, new)) != 0)
    {
      tcsetattr(0, TCSANOW, old);
      return (1);
    }
  return (0);
}
