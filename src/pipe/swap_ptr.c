/*
** swp_ptr.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src/pipe
** 
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
** 
** Started on  Tue May 16 16:49:01 2017 Varé Paul
** Last update Sun May 21 15:16:44 2017 Adrien Bayles
*/

#include "mysh.h"
#include "pipe.h"

void	swap_ptr(char **p1, char **p2)
{
  char  *tmp;

  tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

