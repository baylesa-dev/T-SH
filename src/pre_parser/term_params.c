/*
** term_params.c for term_params in /home/adrien.bayles/Epitech/PSU_2016_42sh/src/pre_parser
** 
** Made by Adrien Bayles
** Login   <adrien.bayles@epitech.net>
** 
** Started on  Sun May 21 13:39:53 2017 Adrien Bayles
** Last update Sun May 21 13:39:54 2017 Adrien Bayles
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
