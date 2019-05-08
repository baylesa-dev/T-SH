/*
** list_pipe.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src/pipe
** 
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
** 
** Started on  Sun May  7 15:40:40 2017 Varé Paul
** Last update Sun May 21 15:10:11 2017 Adrien Bayles
*/

#include "mysh.h"
#include "pipe.h"
#include <stdlib.h>

int	count_av(char *str, int i)
{
  int   ret;

  ret = 0;
  if (str[i] == '|')
    return (1);
  while (str[i] != '\0' && str[i] != '|')
    {
      ret = ret + 1;
      i = i + 1;
    }
  return (ret);
}

char	*get_list_pipe(int *i, char *str)
{
  char  *ret;
  int   j;
  int   len;

  len = count_av(str, *i);
  if (check_empty_cmd(str, i, len))
    return (NULL);
  ret = (char *)malloc(sizeof(char) * (len + 1));
  if (ret == NULL)
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

t_list		*list_pipe(char *str)
{
  t_list        *ret;
  int           i;
  char          *tmp;

  ret = NULL;
  i = 0;
  while (str[i])
    {
      tmp = get_list_pipe(&i, str);
      if (tmp)
        list_insert_front(&ret, tmp);
    }
  return (ret);
}
