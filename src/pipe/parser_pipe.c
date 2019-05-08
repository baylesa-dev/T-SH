/*
** parser_pipe.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src/pipe
** 
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
** 
** Started on  Sun May  7 15:29:17 2017 Varé Paul
** Last update Tue May 16 13:45:53 2017 Varé Paul
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
