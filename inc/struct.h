/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** struct
*/

#ifndef TYPEDEF_H
# define TYPEDEF_H

/*
** typedef
*/
typedef struct		s_rec
{
  char			*rec_cmd;
  struct s_rec		*next;
  struct s_rec		*prev;
}			t_rec;

typedef struct		s_prmpt
{
  int			pos;
  int		        max_p;
  char			*cmd;
  char			*old_cmd;
  t_rec			*rec_first;
  int			len_rec;
  int			pos_rec;
  struct termios	old_trm;
  struct termios	new_trm;
}			t_prmpt;

#endif /* TYPEDEF_H */
