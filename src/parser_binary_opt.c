/*
** parser_binary_opt.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src
** 
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
** 
** Started on  Sun May  7 13:56:47 2017 Varé Paul
** Last update Sun May 21 17:21:52 2017 Alexandre CAUSSADE
*/

#include "mysh.h"
#include "pipe.h"

int		perform_binary_opt(t_list *list, char ***env)
{
  t_list        *path;
  int           ret;

  ret = 0;
  path = list;
  while (path)
    {
      while (path && my_strcmp((char *)path->data, "&&") == 0 && ret == 0)
	path = path->next;
      if (path && my_strcmp((char *)path->data, "||") == 0 && ret != 0)
        path = path->next;
      else if (path && (my_strcmp((char *)path->data, "&&") == 0 ||
                        my_strcmp((char *)path->data, "||") == 0))
        return (ret);
      if (path)
        {
          ret = parser_pipe(path->data, env);
          path = path->next;
        }
    }
  return (ret);
}

int		valid_binary_opt_or(t_list *list)
{
  t_list        *path;

  path = list;
  if (path && my_strcmp((char *)path->data, "||") == 0)
    {
      my_perror("Invalid null command.\n");
      return (1);
    }
  while (path)
    {
      if (my_strcmp((char *)path->data, "||") == 0 &&
          (!path->next || my_strcmp((char *)path->next->data, "||") == 0 ||
           my_strcmp((char *)path->next->data, "&&") == 0))
        {
          my_perror("Invalid null command.\n");
          return (1);
        }
      path = path->next;
    }
  return (0);
}

int		valid_binary_opt_and(t_list *list)
{
  t_list        *path;
  int           bol;

  bol = 0;
  path = list;
  while (path)
    {
      if (my_strcmp((char *)path->data, "||") &&
          my_strcmp((char *)path->data, "&&"))
        bol = 1;
      if (bol && my_strcmp((char *)path->data, "&&") == 0 &&
          (!path->next || my_strcmp((char *)path->next->data, "&&") == 0))
        {
          my_perror("Invalid null command.\n");
          return (1);
        }
      path = path->next;
    }
  return (0);
}

int		parser_binary_opt(char *cmd, char ***env)
{
  t_list        *list;
  int           ret;

  list = binary_opt(cmd);
  if ((ret = valid_binary_opt_or(list)) == 0 &&
      (ret = valid_binary_opt_and(list)) == 0)
    ret = perform_binary_opt(list, env);
  free_list(list);
  return (ret);
}
