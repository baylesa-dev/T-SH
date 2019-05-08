/*
** parser.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src
** 
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
** 
** Started on  Wed May  3 15:23:46 2017 Varé Paul
** Last update Sun May 21 12:00:00 2017 Varé Paul
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
