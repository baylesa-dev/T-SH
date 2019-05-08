/*
** pre_parser.c for pre_parser in /home/adrien.bayles/Epitech/PSU_2016_42sh/src/pre_parser
** 
** Made by Adrien Bayles
** Login   <adrien.bayles@epitech.net>
** 
** Started on  Sun May 21 13:39:11 2017 Adrien Bayles
** Last update Sun May 21 20:29:55 2017 Adrien Bayles
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
