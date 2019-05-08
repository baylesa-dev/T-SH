/*
** my_dollarconcat.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src/builtin
**
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
**
** Started on  Fri May 19 12:52:54 2017 Varé Paul
** Last update Sun May 21 17:11:27 2017 Varé Paul
*/

#include "mysh.h"
#include "builtin.h"
#include <stdlib.h>

int	my_dollarlen(char *str)
{
  int   i;

  if (!str)
    return (0);
  i = 0;
  while (str[i] && str[i] != '$')
    i = i + 1;
  return (i);
}

char	*my_dollarconcat(char *s1, char *s2)
{
  char	*ret;
  int   i;
  int   j;

  ret = (char *)malloc(sizeof(char) * (my_strlen(s1) + my_dollarlen(s2) + 1));
  if (!ret)
    return (NULL);
  i = 0;
  j = 0;
  while (s1 && s1[i])
    {
      ret[j] = s1[i];
      i = i + 1;
      j = j + 1;
    }
  i = 0;
  while (i < my_dollarlen(s2))
    {
      ret[j] = s2[i];
      i = i + 1;
      j = j + 1;
    }
  ret[j] = '\0';
  (s1 ? free(s1) : 0);
  return (ret);
}
