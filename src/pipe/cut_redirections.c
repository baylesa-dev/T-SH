/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** cut_redirections
*/

#include "mysh.h"
#include "pipe.h"
#include <stdlib.h>

int	detect_redirection(char *cmd)
{
  int   i;

  i = 0;
  while (cmd[i])
    {
      if (cmd[i] == '<' || cmd[i] == '>')
        return (1);
      i = i + 1;
    }
  return (0);
}

t_list	*insert_cut_str(char *str, int len, t_list **list)
{
  char  *tmp;
  int   i;

  tmp = (char *)malloc(sizeof(char) * (len + 1));
  if (!tmp)
    return (NULL);
  i = 0;
  while (i < len)
    {
      tmp[i] = str[i];
      i = i + 1;
    }
  tmp[i] = '\0';
  list_insert_front(list, tmp);
  tmp = my_strdup(&str[len]);
  if (!tmp)
    return (NULL);
  list_insert_front(list, tmp);
  return (*list);
}

t_list		*cut_redirection(char *cmd)
{
  t_list        *ret;
  int           i;
  int           bol;

  ret = NULL;
  i = 0;
  bol = 0;
  while (cmd[i])
    {
      if (((cmd[i] == '<' && cmd[i + 1] != '>') ||
           (cmd[i] == '>' && cmd[i + 1] != '<')))
        {
          if (!bol && (cmd[i + 1] == '>' || cmd[i + 1] == '<'))
            i = i + 1;
          if (bol)
            return (insert_cut_str(cmd, i, &ret));
          bol = 1;
        }
      i = i + 1;
    }
  list_insert_front(&ret, my_strdup(cmd));
  return (ret);
}
