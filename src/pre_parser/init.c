/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** init
*/

#include "preparser.h"

int		free_all(t_prmpt *prmpt)
{
  if (prmpt->cmd)
    free(prmpt->cmd);
  if (prmpt->old_cmd)
    free(prmpt->old_cmd);
  free(prmpt->rec_first);
  return (0);
}

t_rec		*init_rec(void)
{
  t_rec		*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->rec_cmd = NULL;
  new->next = NULL;
  new->prev = NULL;
  return (new);
}

t_prmpt		*init_prompt(void)
{
  t_prmpt	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->pos = new->max_p = 0;
  if ((new->cmd = malloc(sizeof(char))) == NULL)
    return (NULL);
  new->cmd = '\0';
  new->old_cmd = NULL;
  if ((new->rec_first = init_rec()) == NULL)
    return (NULL);
  new->len_rec = new->pos_rec = 0;
  return (new);
}
