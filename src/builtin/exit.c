/*
** exit.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src/builtin
**
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
**
** Started on  Sat May  6 21:57:20 2017 Varé Paul
** Last update Sun May 21 17:10:29 2017 Varé Paul
*/

#include "mysh.h"
#include "builtin.h"
#include <stdlib.h>

int	my_exit(char **tab, char ***env, char *cmd)
{
  (void)tab;
  (void)env;
  (void)cmd;
  if (tab[1] && tab[2])
    {
      my_perror("exit: Expression Syntax.\n");
      return (1);
    }
  if (tab[1])
    {
      if (is_a_number(tab[1]) == 0)
	{
	  if (tab[1][0] >= '0' && tab[1][0] <= '9')
	    my_perror("exit: Badly formed number.\n");
	  else
	    my_perror("exit: Expression Syntax.\n");
	  return (1);
	}
      exit((unsigned char)my_get_nbr(tab[1]));
    }
  exit(0);
  return (0);
}
