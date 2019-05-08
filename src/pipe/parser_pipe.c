/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** parser_pipe
*/

#include "mysh.h"
#include "pipe.h"

int	error_parser(t_list *list, t_list *table)
{
  free_list(list);
  free_list_table(table);
  return (1);
}

int		parser_pipe(char *cmd, char ***env)
{
  t_list	*list;
  t_list	*table;
  int		ret;

  (void)env;
  table = NULL;
  list = list_pipe(cmd);
  if (lexer_pipe(list))
    return (error_parser(list, table));
  table = parser_table(list);
  if (!table)
    return (error_parser(list, table));
  if (lexer_redirections(table))
    return (error_parser(list, table));
  ret = executor_pipe(table, env);
  free_list_table(table);
  free_list(list);
  return (ret);
}
