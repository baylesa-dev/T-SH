/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** my_printf
*/

#include "my.h"
#include <stdlib.h>

int	find_char_in_str(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (1);
      i = i + 1;
    }
  return (0);
}

int	print_arg(va_list *ap, char *cmp, char c)
{
  void	(*ptr[5])(va_list *ap);
  int	i;

  ptr[0] = f_str;
  ptr[1] = f_nbr;
  ptr[2] = f_nbr;
  ptr[3] = f_char;
  ptr[4] = f_error;
  i = 0;
  while (cmp[i])
    {
      if (cmp[i] == c)
	{
	  ptr[i](ap);
	  return (0);
	}
      i = i + 1;
    }
  return (0);
}

int	parser_str(char *str, va_list *ap)
{
  int	i;
  int	bol;
  char	*cmp;

  if ((cmp = my_strdup("sidcp")) == NULL)
    return (84);
  i = 0;
  while (str[i])
    {
      bol = 0;
      if (str[i] == '%')
	{
	  if (find_char_in_str(cmp, str[i + 1]))
	    {
	      print_arg(ap, cmp, str[i + 1]);
	      bol = 1;
	      i = i + 1;
	    }
	}
      if (!bol)
	my_putchar(str[i]);
      i = i + 1;
    }
  free(cmp);
  return (0);
}

int		my_printf(char *str, ...)
{
  va_list	ap;

  va_start(ap, str);
  parser_str(str, &ap);
  va_end(ap);
  return (0);
}
