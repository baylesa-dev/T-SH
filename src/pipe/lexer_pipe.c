/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** lexer_pipe
*/

#include "mysh.h"
#include "pipe.h"

int	error_pipe(int code)
{
  if (code == 0)
    return (0);
  if (code == 1)
    my_perror("Invalid null command.\n");
  if (code == 2)
    my_perror("Missing name for redirect.\n");
  if (code == 3)
    my_perror("Ambiguous input redirect.\n");
  if (code == 4)
    my_perror("Ambiguous output redirect.\n");
  return (1);
}

int		lexer_pipe(t_list *list)
{
  t_list	*path;

  path = list;
  if (path && my_strcmp(path->data, "|") == 0)
    return (error_pipe(1));
  while (path)
    {
      if (my_strcmp(path->data, "|") == 0 &&
	  ((path->next && my_strcmp(path->next->data, "|") == 0)
	   || !path->next))
	return (error_pipe(1));
      path = path->next;
    }
  return (0);
}

int	check_missing_redirection(t_table *s_table, t_table *tmp)
{
  int	ret;

  ret = 0;
  if (s_table->redirec > 0 && s_table->redirec < 3)
    {
      if (is_a_cmd(s_table->input) == 0)
	ret = 1;
      if (is_a_cmd(s_table->output) == 0)
	ret = 2;
    }
  if (s_table->redirec > 2)
    {
      if (is_a_cmd(s_table->output) == 0)
	ret = 1;
      if (is_a_cmd(s_table->input) == 0)
	ret = 2;
    }
  if (ret == 1 && (!tmp || (tmp && (tmp->redirec == 3 || tmp->redirec == 4))))
    return (0);
  else
    return (error_pipe(ret));
  return (0);
}

int	check_ambigous(t_table *s_table, t_list *next, t_table *tmp)
{
  if (s_table->redirec > 0 && s_table->redirec < 3 && next)
    return (error_pipe(4));
  if (s_table->redirec > 2 && tmp)
    return (error_pipe(3));
  return (0);
}

int		lexer_redirections(t_list *table)
{
  t_list	*path;
  t_table	*s_table;
  t_table	*tmp;
  t_list	*next;

  tmp = NULL;
  path = table;
  while (path)
    {
      s_table = (t_table *)path->data;
      next = path->next;
      if (check_missing_redirection(s_table, tmp) ||
	  check_ambigous(s_table, next, tmp))
	return (1);
      tmp = s_table;
      path = path->next;
    }
  return (0);
}
