/*
** free.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src
** 
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
** 
** Started on  Thu May  4 10:42:07 2017 Varé Paul
** Last update Tue May  9 11:34:03 2017 Varé Paul
*/

#include "mysh.h"
#include "pipe.h"
#include <stdlib.h>

void		free_list_table(t_list *list)
{
  t_list	*tmp;
  t_table	*table;

  while (list)
    {
      tmp = list;
      list = list->next;
      table = (t_table *)tmp->data;
      if (table->cmd)
        free(table->cmd);
      if (table->input)
	free(table->input);
      if (table->output)
	free(table->output);
      free(table);
      free(tmp);
    }
}

void		free_list(t_list *list)
{
  t_list	*tmp;

  while (list)
    {
      tmp = list;
      list = list->next;
      if (tmp->data)
	free(tmp->data);
      free(tmp);
    }
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i = i + 1;
    }
  free(tab);
}

void	free_3tab(char ***tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free_tab(tab[i]);
      i = i + 1;
    }
  free(tab);
}
