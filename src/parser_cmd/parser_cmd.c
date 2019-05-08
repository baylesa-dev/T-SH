/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** parser_cmd
*/

#include "mysh.h"
#include "parser_cmd.h"
#include "builtin.h"
#include <stdlib.h>
#include <unistd.h>

int	change_value(char **tab, int *i, char *tmp, int *j)
{
  if (tmp)
    {
      free(tab[*i]);
      tab[*i] = tmp;
    }
  else
    {
      *j = *j + 1;
      while (tab[*i][*j] && tab[*i][*j] != '$')
	{
	  write(2, &tab[*i][*j], 1);
	  *j = *j + 1;
	}
      my_perror(": Undefined variable.\n");
      return (1);
    }
  *j = my_strlen(tab[*i]) - 1;
  return (0);
}

int	parser_var_interpreted(char **tab, char **env)
{
  int	i;
  int	j;
  char	*tmp;

  i = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	{
	  if (tab[i][j] == '$')
	    {
	      tmp = my_varconcat(tab[i], env);
	      if (change_value(tab, &i, tmp, &j))
		return (1);
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
  return (0);
}

int	perform_globbing(char *cmd, char ***tab)
{
  if (detect_globbing(cmd))
    {
      if (!(*tab = globbing(*tab)))
        return (1);
    }
  return (0);
}

char	**parser_cmd(char *cmd, char ***env)
{
  char	**ret;

  ret = my_str_to_wordtab(cmd);
  if (!ret)
    return (0);
  if (parser_var_interpreted(ret, *env))
    return (0);
  if (perform_globbing(cmd, &ret))
    return (0);
  return (ret);
}
