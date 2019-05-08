/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** which
*/

#include "mysh.h"
#include "builtin.h"

int	which(char **tab, char ***env, char *cmd)
{
  int	i;

  (void)cmd;
  i = 1;
  if (!tab[1])
    my_printf("Which: Too few arguments.\n");
  else
    {
      while (tab[i])
        {
          if (is_bultin(tab[i]) == 0)
            {
	      my_printf("%s: shell built-in command.\n", tab[i]);
              i++;
            }
          else
            {
              perform_where(*env, tab[i]);
              i++;
            }
        }
    }
  return (1);
}
