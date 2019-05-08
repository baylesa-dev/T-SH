/*
** typedef.h for typedef in /home/adrnnc/Epitech/Semestre2/SHELL/dev/enfindev
**
** Made by Adrien Bayles
** Login   <adrien.bayles@epitech.eu>
**
** Started on  Thu May 18 09:41:19 2017 Adrien Bayles
** Last update Sun May 21 17:31:56 2017 Varé Paul
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
