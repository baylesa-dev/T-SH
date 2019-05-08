/*
** tab.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src
**
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
**
** Started on  Sat May  6 18:35:04 2017 Varé Paul
** Last update Sun May 21 17:16:07 2017 Varé Paul
*/

#include "mysh.h"
#include "builtin.h"

int	my_tablen(char **tab)
{
  int	i;

  if (!tab)
    return (0);
  i = 0;
  while (tab[i])
    i = i + 1;
  return (i);
}

int	aff_env(char **tab, char ***env, char *cmd)
{
  int	i;

  (void)tab;
  (void)cmd;
  i = 0;
  while (env[0][i])
    {
      my_putstr(env[0][i]);
      my_putchar('\n');
      i = i + 1;
    }
  return (0);
}

int	aff_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
  return (0);
}
