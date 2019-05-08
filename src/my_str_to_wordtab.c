/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** my_str_to_wordtab
*/

#include "mysh.h"
#include <stdlib.h>

int	count_words(char *str)
{
  int	i;
  int	ct;

  i = 0;
  ct = 0;
  if (str[0] != ' ' && str[0] != '\t' && str[0] != '\0')
    ct = ct + 1;
  while (str[i + 1])
    {
      if ((str[i] == ' ' || str[i] == '\t') &&
	  (str[i + 1] != ' ' && str[i + 1] != '\t'))
	ct = ct + 1;
      i = i + 1;
    }
  return (ct);
}

int	my_wordlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] && str[i] != ' ' && str[i] != '\t')
    i = i + 1;
  return (i);
}

void	assign_word(char *assign, char *src, int *i)
{
  int	j;

  j = 0;
  while (src[*i] && src[*i] != ' ' && src[*i] != '\t')
    {
      assign[j] = src[*i];
      j = j + 1;
      *i = *i + 1;
    }
  assign[j] = '\0';
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	i;
  int	j;

  tab = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
  i = 0;
  j = 0;
  while (str[i])
    {
      while (str[i] == ' ' || str[i] == '\t')
	i = i + 1;
      if (str[i])
	{
	  tab[j] = (char *)malloc(sizeof(char) * (my_wordlen(&str[i]) + 1));
	  assign_word(tab[j], str, &i);
	  j = j + 1;
	}
    }
  tab[j] = NULL;
  return (tab);
}
