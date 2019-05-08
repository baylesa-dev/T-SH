/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** tab
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
