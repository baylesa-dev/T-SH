/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** my
*/

#ifndef MY_H
# define MY_H

#include <stdarg.h>
#define	READ_SIZE	4096

typedef struct  s_list
{
  void          *data;
  struct s_list *next;
}               t_list;

/*
** my_putchar.c
*/
void	my_putchar(char c);

/*
** my_strlen.c
*/
int	my_strlen(char *str);

/*
** my_putstr.c
*/
void	my_putstr(char *str);

/*
** my_put_nbr.c
*/
void	my_put_nbr(int nb);

/*
** my_strdup.c
*/
char	*my_strdup(char *str);

/*
** my_strcmp.c
*/
int	my_strcmp(char *s1, char *s2);

/*
** my_strncmp.c
*/
int	my_strncmp(char *s1, char *s2, int size);

/*
** my_get_nbr.c
*/
int	my_get_nbr(char *str);

/*
** my_list.c
*/
t_list	*list_create_node(void *data);
void	list_insert_front(t_list **begin_list, void *data);
t_list	*list_insert_back(t_list **begin_list, void *data);

/*
** my_perror.c
*/
void	my_perror(char *str);

/*
** my_printf.c
*/
int	my_printf(char *str, ...);

/*
** my_printf_ptr_func.c
*/
void    f_str(va_list *ap);
void    f_nbr(va_list *ap);
void	f_char(va_list *ap);
void	f_error(va_list *ap);

/*
** get_next_line.c
*/
char	*get_next_line(const int fd);
char	*my_strconcat(char *s1, char *s2);

#endif /* !MY_H */
