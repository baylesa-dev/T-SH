/*
** which.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src/builtin
** 
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
** 
** Started on  Sat May 20 19:07:32 2017 Varé Paul
** Last update Sun May 21 17:17:53 2017 Varé Paul
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
