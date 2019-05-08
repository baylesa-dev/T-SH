/*
** alpha_num.c for alpha_num in /home/adrien.bayles/Epitech/PSU_2016_42sh/src/pre_parser
** 
** Made by Adrien Bayles
** Login   <adrien.bayles@epitech.net>
** 
** Started on  Sun May 21 13:37:44 2017 Adrien Bayles
** Last update Sun May 21 13:37:49 2017 Adrien Bayles
*/

#include "preparser.h"

int	insert_add(t_prmpt *prmpt, char *buff)
{
  int	i;
  int	j;

  i = j = 0;
  prmpt->old_cmd = my_strdup(prmpt->cmd);
  free(prmpt->cmd);
  prmpt->cmd = malloc(sizeof(char) * (my_strlen(prmpt->old_cmd) + 2));
  if (prmpt->cmd == NULL)
    return (84);
  prmpt->cmd[my_strlen(prmpt->old_cmd) + 1] = '\0';
  while (prmpt->old_cmd[i] && i < prmpt->pos)
    {
      prmpt->cmd[j] = prmpt->old_cmd[i];
      i++;
      j++;
    }
  prmpt->cmd[j] = buff[0];
  while (prmpt->old_cmd[i])
    {
      prmpt->cmd[++j] = prmpt->old_cmd[i];
      i++;
    }
  return (0);
}

char	*add_new_char(t_prmpt *prmpt, char *buff)
{
  int	i;

  i = 0;
  prmpt->old_cmd = my_strdup(prmpt->cmd);
  free(prmpt->cmd);
  prmpt->cmd = malloc(sizeof(char) * (my_strlen(prmpt->old_cmd) + 2));
  if (prmpt->cmd == NULL)
    return (NULL);
  prmpt->cmd[my_strlen(prmpt->old_cmd) + 1] = '\0';
  while (prmpt->old_cmd[i] != '\0')
    {
      prmpt->cmd[i] = prmpt->old_cmd[i];
      i++;
    }
  prmpt->cmd[i] = buff[0];
  return (prmpt->cmd);
}

int	simple_add(t_prmpt *prmpt, char *buff)
{
  if (prmpt->cmd)
    {
      prmpt->cmd = add_new_char(prmpt, buff);
    }
  else
    {
      if ((prmpt->cmd = malloc(sizeof(char) * 2)) == NULL)
	return (84);
      prmpt->cmd[1] = '\0';
      prmpt->cmd[0] = buff[0];
    }
  return (0);
}

int	alpha_num(t_prmpt *prmpt, char *buff)
{
  if (prmpt->pos == prmpt->max_p)
    simple_add(prmpt, buff);
  else
    insert_add(prmpt, buff);
  clean_line(prmpt);
  write(1, prmpt->cmd, my_strlen(prmpt->cmd));
  prmpt->max_p = my_strlen(prmpt->cmd);
  prmpt->pos++;
  replace_cursor(prmpt);
  return (0);
}
