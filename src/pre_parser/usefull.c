/*
** usefull.c for usefull in /home/adrien.bayles/Epitech/PSU_2016_42sh/src/pre_parser
** 
** Made by Adrien Bayles
** Login   <adrien.bayles@epitech.net>
** 
** Started on  Sun May 21 13:40:02 2017 Adrien Bayles
** Last update Sun May 21 13:40:03 2017 Adrien Bayles
*/

#include "preparser.h"

int	get_lenght_max(char **tab)
{
  int	i;
  int	j;

  i = j = 0;
  while (tab[i])
    {
      if (j < my_strlen(tab[i]))
	j = my_strlen(tab[i]);
      i++;
    }
  return (j);
}

int	my_len(char **tab)
{
  int	i;

  i = 0;
  if (!tab)
    return (1);
  while (tab[i])
    i++;
  return (i + 1);
}

char	**add_to_tab(char *str, char **tab)
{
  char  **new;
  int   i;

  i = 0;
  if ((new = malloc(sizeof(char *) * (my_len(tab) + 1))) == NULL)
    return (NULL);
  new[my_len(tab)] = NULL;
  if (tab)
    {
      while (tab[i])
	{
	  new[i] = my_strdup(tab[i]);
	  free(tab[i]);
	  i++;
	}
    }
  free(tab);
  new[i] = my_strdup(str);
  return (new);
}
