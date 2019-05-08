/*
** parser_binary_opt.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src
**
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
**
** Started on  Thu May  4 11:29:33 2017 Varé Paul
** Last update Sun May  7 13:12:46 2017 Varé Paul
*/

#include "mysh.h"
#include <stdlib.h>

int	my_binary_opt_len(char *str)
{
  int	i;

  if (str[0] == '&' && str[1] == '&')
    return (2);
  if (str[0] == '|' && str[1] == '|')
    return (2);
  i = 0;
  while (str[i])
    {
      if ((str[i] == '&' && str[i + 1] == '&') ||
	  (str[i] == '|' && str[i + 1] == '|'))
	return (i);
      i = i + 1;
    }
  return (i);
}

int	check_empty_cmd(char *str, int *index, int len)
{
  int	i;

  i = *index;
  while (i < *index + len)
    {
      if (str[i] != ' ')
	return (0);
      i = i + 1;
    }
  i = 0;
  while (i < len)
    {
      *index = *index + 1;
      i = i + 1;
    }
  return (1);
}

char	*get_binary_opt_str(char *str, int *i)
{
  char	*ret;
  int	len;
  int	j;

  len = my_binary_opt_len(&str[*i]);
  if (check_empty_cmd(str, i, len))
    return (NULL);
  ret = (char *)malloc(sizeof(char) * (len + 1));
  if (!ret)
    return (NULL);
  j = 0;
  while (j < len)
    {
      ret[j] = str[*i];
      *i = *i + 1;
      j = j + 1;
    }
  ret[j] = '\0';
  return (ret);
}

t_list		*binary_opt(char *cmd)
{
  t_list	*list;
  char		*tmp;
  int		i;

  list = NULL;
  i = 0;
  while (cmd[i])
    {
      tmp = get_binary_opt_str(cmd, &i);
      if (tmp)
	list_insert_front(&list, tmp);
    }
  return (list);
}
