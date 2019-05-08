/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** parser.c
*/

#include "mysh.h"
#include "pipe.h"

int		parser(char *cmd, char ***env)
{
  t_list	*list;
  t_list	*path;
  int		ret;

  ret = 0;
  list = semi_colon(cmd);
  path = list;
  while (path)
    {
      if (is_a_cmd(path->data))
	ret = parser_binary_opt(path->data, env);
      path = path->next;
    }
  free_list(list);
  return (ret);
}
