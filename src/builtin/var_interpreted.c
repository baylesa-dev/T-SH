/*
** var_interpreted.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src/builtin
**
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
**
** Started on  Fri May 19 11:08:50 2017 Varé Paul
** Last update Sun May 21 17:16:30 2017 Varé Paul
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
