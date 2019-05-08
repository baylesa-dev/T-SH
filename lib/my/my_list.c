/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** my_list
*/

#include "my.h"
#include <stdlib.h>

t_list		*list_create_node(void *data)
{
  t_list	*elem;

  elem = (t_list *)malloc(sizeof(t_list));
  elem->next = NULL;
  elem->data = data;
  return (elem);
}

void		list_insert_front(t_list **begin_list, void *data)
{
  t_list	*list;
  t_list	*elem;

  list = *begin_list;
  if (list)
    {
      while (list->next)
	list = list->next;
      elem = list_create_node(data);
      elem->next = NULL;
      elem->data = data;
      list->next = elem;
    }
  else
    *begin_list = list_create_node(data);
}

t_list		*list_insert_back(t_list **begin_list, void *data)
{
  t_list	*elem;

  elem = list_create_node(data);
  elem->next = *begin_list;
  return (elem);
}
