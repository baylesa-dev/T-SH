/*
** parser_semi_colon.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src
** 
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
** 
** Started on  Wed May  3 15:40:25 2017 Varé Paul
** Last update Sun May 21 17:22:55 2017 Alexandre CAUSSADE
*/

#include "mysh.h"
#include <stdlib.h>

int	len_semi_colon(int i, char *str)
{
  int   ret;

  ret = 0;
  while (str[i] != '\0' && str[i] != ';')
    {
      ret = ret + 1;
      i = i + 1;
    }
  return (ret);
}

char	*parse_semi_colon(int *i, char *str)
{
  char  *ret;
  int   j;

  ret = malloc(sizeof(char) * (len_semi_colon(*i, str) + 1));
  if (ret == NULL)
    return (NULL);
  j = 0;
  while (str[*i] != '\0' && str[*i] != ';')
    {
      ret[j] = str[*i];
      j = j + 1;
      *i = *i + 1;
    }
  ret[j] = '\0';
  if (str[*i] == ';')
    *i = *i + 1;
  return (ret);
}

t_list		*semi_colon(char *str)
{
  t_list        *list;
  char          *tmp;
  int           i;

  i = 0;
  list = NULL;
  while (str[i])
    {
      tmp = parse_semi_colon(&i, str);
      if (tmp == NULL)
        return (NULL);
      if (tmp[0] != '\0')
        list_insert_front(&list, tmp);
    }
  return (list);
}
