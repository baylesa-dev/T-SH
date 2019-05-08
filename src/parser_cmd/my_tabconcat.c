/*
** my_tabconcat.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src/parser_cmd
** 
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
** 
** Started on  Fri May 19 17:04:39 2017 Varé Paul
** Last update Sun May 21 15:22:33 2017 Adrien Bayles
*/

#include "mysh.h"
#include "parser_cmd.h"
#include "builtin.h"
#include <stdlib.h>

int	add_elem_tab(char ***tab, char *add)
{
  char  **new;
  int   i;

  new = (char **)malloc(sizeof(char *) * (my_tablen(*tab) + 2));
  if (!new)
    return (1);
  i = 0;
  while (*tab && tab[0][i])
    {
      new[i] = tab[0][i];
      i = i + 1;
    }
  new[i] = add;
  new[i + 1] = 0;
  free(*tab);
  *tab = new;
  return (0);
}

char	**my_tabconcat(char **tab1, char **tab2)
{
  int	i;
  char	**ret;

  ret = NULL;
  i = 0;
  while (tab1 && tab1[i])
    {
      add_elem_tab(&ret, tab1[i]);
      i = i + 1;
    }
  i = 0;
  while (tab2 && tab2[i])
    {
      add_elem_tab(&ret, tab2[i]);
      i = i + 1;
    }
  if (tab1)
    free(tab1);
  if (tab2)
    free(tab2);
  return (ret);
}
