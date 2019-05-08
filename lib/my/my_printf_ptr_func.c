/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** my_printf_ptr_func
*/

#include "my.h"

void	f_str(va_list *ap)
{
  char	*str;

  str = va_arg(*ap, char *);
  my_putstr(str);
}

void	f_nbr(va_list *ap)
{
  int	nb;

  nb = va_arg(*ap, int);
  my_put_nbr(nb);
}

void	f_char(va_list *ap)
{
  char	c;

  c = va_arg(*ap, int);
  my_putchar(c);
}

void	f_error(va_list *ap)
{
  char	*str;

  str = va_arg(*ap, char *);
  my_perror(str);
}
