/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** echo
*/

#include "mysh.h"
#include "builtin.h"
#include "parser_cmd.h"
#include <stdlib.h>

char	**my_str_to_tabcmd(char *str, char **env)
{
  int	i;
  char	**ret;
  int	val;

  ret = NULL;
  i = 0;
  while (str[i])
    {
      while (str[i] == ' ' || str[i] == '\t')
	i = i + 1;
      if ((val = double_quote(str, &i, &ret, env)) == 1)
	return (0);
      if (val == -1 && (val = simple_quote(str, &i, &ret)) == 1)
	return (0);
      if (val == -1)
	no_quote(str, &i, &ret, env);
    }
  return (ret);
}

void	move_to_param(char *str, int *i)
{
  while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
    *i = *i + 1;
  while (str[*i] && str[*i] != ' ' && str[*i] != '\t')
    *i = *i + 1;
  while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
    *i = *i + 1;
  if (str[*i] && str[*i] == '-' && str[*i + 1] == 'n')
    {
      *i = *i + 2;
      while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
  	*i = *i + 1;
    }
}

int	echo(char **tab, char ***env, char *cmd)
{
  char	**tab_cmd;
  int	i;

  i = 0;
  move_to_param(cmd, &i);
  tab_cmd = my_str_to_tabcmd(&cmd[i], *env);
  i = 0;
  while (tab_cmd && tab_cmd[i])
    {
      my_putstr(tab_cmd[i]);
      if (tab_cmd[i + 1])
	my_putchar(' ');
      i = i + 1;
    }
  if (tab_cmd)
    free_tab(tab_cmd);
  if (tab[1] && my_strcmp(tab[1], "-n") == 0)
    return (0);
  my_putchar('\n');
  return (0);
}
