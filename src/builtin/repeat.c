/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** repeat
*/

#include "mysh.h"
#include "builtin.h"

int	is_a_number(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '-')
    i = i + 1;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i = i + 1;
    }
  return (1);
}

int	repeat_exec(char *cmd, char ***env, int nb)
{
  int	i;
  int	ret;

  ret = 0;
  i = 0;
  while (i < nb)
    {
      ret = execution(cmd, env);
      i = i + 1;
    }
  return (ret);
}

int	move_in_cmd(char *cmd)
{
  int	i;
  int	j;

  i = 0;
  j  = 0;
  while (j < 2)
    {
      while (cmd[i] == ' ' || cmd[i] == '\t')
	i = i + 1;
      while (cmd[i] != ' ' && cmd[i] != '\t')
	i = i + 1;
      j = j + 1;
    }
  return (i);
}

int	repeat(char **tab, char ***env, char *cmd)
{
  int	i;

  if (!tab[1] || !tab[2])
    {
      my_perror("repeat: Too few arguments.\n");
      return (1);
    }
  if (is_a_number(tab[1]) == 0)
    {
      my_perror("repeat: Badly formed number.\n");
      return (1);
    }
  i = move_in_cmd(cmd);
  return (repeat_exec(&cmd[i], env, my_get_nbr(tab[1])));
}
