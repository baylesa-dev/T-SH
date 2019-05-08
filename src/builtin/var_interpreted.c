/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** var_interpreted
*/

#include "mysh.h"
#include "builtin.h"
#include <stdlib.h>

int	var_interpreted(char **tab, char ***env)
{
  char	*tmp;
  int	ret;
  int	i;

  tmp = my_varconcat(tab[0], *env);
  if (!tmp)
    {
      my_perror(&tab[0][1]);
      my_perror(": Undefined variable.\n");
      return (1);
    }
  i = 0;
  while (tmp[i] == '$')
    i = i + 1;
  if (i == my_strlen(tmp))
    {
      my_perror(&tab[0][1]);
      my_perror(": Command not found.\n");
      ret = 1;
    }
  else
    ret = execution(tmp, env);
  free(tmp);
  return (ret);
}
