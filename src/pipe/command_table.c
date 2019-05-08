/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** command_table
*/

#include "mysh.h"
#include "pipe.h"
#include <stdlib.h>

t_table		*init_for_pipe(char *cmd)
{
  t_table	*ret;

  ret = (t_table *)malloc(sizeof(t_table));
  if (!ret)
    return (NULL);
  ret->cmd = my_strdup(cmd);
  ret->pid = 0;
  ret->status = 0;
  ret->redirec = 0;
  ret->input = NULL;
  ret->output = NULL;
  return (ret);
}

int	get_operator(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '>' && str[i + 1] == '>')
	return (2);
      if (str[i] == '<' && str[i + 1] == '<')
	return (4);
      if (str[i] == '>')
	return (1);
      if (str[i] == '<')
	return (3);
      i = i + 1;
    }
  return (0);
}

t_table		*create_table_redirection(char *str)
{
  t_table	*ret;

  ret = (t_table *)malloc(sizeof(t_table));
  if (!ret)
    return (NULL);
  ret->cmd = NULL;
  ret->redirec = get_operator(str);
  ret->input = get_input(str);
  ret->output = get_ouput(str);
  ret->pid = 0;
  ret->status = 0;
  if (ret->input == NULL || ret->output == NULL)
    return (NULL);
  return (ret);
}

int		init_for_redirection(char *cmd, t_list **table)
{
  t_list	*list;
  t_list	*path;
  t_table	*new;

  if (!detect_redirection(cmd))
    return (0);
  list = cut_redirection(cmd);
  path = list;
  while (path)
    {
      new = create_table_redirection(path->data);
      if (new->redirec == 1 || new->redirec == 2)
	swap_ptr(&new->input, &new->output);
      if (new)
	list_insert_front(table, new);
      path = path->next;
    }
  free_list(list);
  return (1);
}

t_list		*parser_table(t_list *list)
{
  t_list	*path;
  t_list	*table;
  t_table	*new;

  table = NULL;
  path = list;
  while (path)
    {
      if (my_strcmp(path->data, "|"))
	{
	  new = NULL;
	  if (!init_for_redirection(path->data, &table))
	    new = init_for_pipe(path->data);
	  if (new)
	    list_insert_front(&table, new);
	}
      path = path->next;
    }
  return (table);
}
