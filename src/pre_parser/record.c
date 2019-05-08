/*
** record.c for record in /home/adrien.bayles/Epitech/PSU_2016_42sh/src/pre_parser
** 
** Made by Adrien Bayles
** Login   <adrien.bayles@epitech.net>
** 
** Started on  Sun May 21 13:39:21 2017 Adrien Bayles
** Last update Sun May 21 13:39:22 2017 Adrien Bayles
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
