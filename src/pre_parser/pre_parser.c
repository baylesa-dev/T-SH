/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** pre_parser
*/

#include "preparser.h"

char	*read_prompt(t_prmpt *prmpt)
{
  char	buff[5];

  while (read(0, buff, 5) != 0 && buff[0] != '\n')
    {
      if (buff[0] > 31 && buff[0] < 127)
	alpha_num(prmpt, buff);
      else
	sequence(prmpt, buff);
    }
  write(1, "\n", 1);
  if (prmpt->cmd == NULL)
    return (NULL);
  if (prmpt->cmd != NULL  && prmpt->cmd[0] != '\0' && prmpt->cmd[0] != '\n')
    prmpt->rec_first = add_to_list(&prmpt->rec_first, prmpt->cmd, prmpt);
  return (prmpt->cmd);
}

char	*pre_parsing(t_prmpt *prmpt)
{
  char	*str;

  tcsetattr(0, TCSANOW, &prmpt->new_trm);
  if ((str = read_prompt(prmpt)) == NULL)
    {
      tcsetattr(0, TCSANOW, &prmpt->old_trm);
      return (NULL);
    }
  tcsetattr(0, TCSANOW, &prmpt->old_trm);
  return (str);
}
