/*
** get_input.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src/pipe
** 
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
** 
** Started on  Tue May 16 16:34:12 2017 Varé Paul
** Last update Sun May 21 15:06:13 2017 Adrien Bayles
*/

#include "mysh.h"
#include "pipe.h"
#include <stdlib.h>

int	my_inputlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i = i + 1;
  while (str[i] && str[i] != ' ' && str[i] != '\t')
    i = i + 1;
  return (i);
}

char	*get_input(char *str)
{
  int   i;
  int   j;
  char  *ret;

  i = 0;
  while (str[i] && str[i] != '<' && str[i] != '>')
    i = i + 1;
  if ((str[i] == '>' && str[i + 1] == '>') ||
      (str[i] == '<' && str[i + 1] == '<'))
    i = i + 1;
  i = i + 1;
  ret = (char *)malloc(sizeof(char) * (my_inputlen(&str[i]) + 1));
  if (!ret)
    return (NULL);
  while (str[i] == ' ' || str[i] == '\t')
    i = i + 1;
  j = 0;
  while (str[i] && str[i] != ' ' && str[i] != '\t')
    {
      ret[j] = str[i];
      j = j + 1;
      i = i + 1;
    }
  ret[j] = '\0';
  return (ret);
}
