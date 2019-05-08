/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** record
*/

#include "preparser.h"

t_rec	*create_first_node(char *data)
{
  t_rec	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->next = NULL;
  new->rec_cmd = my_strdup(data);
  return (new);
}

t_rec	*add_to_list(t_rec **first, char *data, t_prmpt *prmpt)
{
  t_rec	*new;

  new = create_first_node(data);
  new->next = *first;
  prmpt->len_rec++;
  return (new);
}
