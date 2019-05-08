/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** preparser
*/

#ifndef PREPARSER_H
# define PREPARSER_H

#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include "mysh.h"
#include "my.h"
#include "struct.h"
/*
** record_display.c
*/
int	clean_record(t_prmpt *prmpt);
int	erase_record(t_prmpt *prmpt);
int	record_down(t_prmpt *prmpt);
int	record_up(t_prmpt *prmpt);

/*
** record.c
*/
t_rec	*create_first_node(char *data);
t_rec	*add_to_list(t_rec **first, char *data, t_prmpt *prmpt);

/*
** usefull.c
*/
int	get_lenght_max(char **tab);
int	my_len(char **tab);
char	**add_to_tab(char *str, char **tab);

/*
** auto_complete.c
*/
char	*my_strtrickconcat(char *s1, char *s2, int pos);
int	display_multi(t_prmpt *prmpt, char **tab);
int	display_one(t_prmpt *prmpt, char **tab, int pos);
char	**get_files(char *str);
int	auto_complete(t_prmpt *prmpt);

/*
** clean.c
*/
int	replace_cursor(t_prmpt *prmpt);
int	clean_line(t_prmpt *prmpt);
int	clear_screen(t_prmpt *prmpt);

/*
** record_display.c
*/
int	record_down(t_prmpt *prmpt);
int	record_up(t_prmpt *prmpt);

/*
** cursor.c
*/
int	cursor_left(t_prmpt *prmpt);
int	cursor_right(t_prmpt *prmpt);

/*
** erase.c
*/
int	display_delete(t_prmpt *prmpt);
int	delete_key(t_prmpt *prmpt);
int	hard_erase(t_prmpt *prmpt);
int	simple_erase(t_prmpt *prmpt);
int	erase_char(t_prmpt *prmpt);

/*
** control.c
*/
int     control_d(t_prmpt *prmpt);
int     control_c(t_prmpt *prmpt);
int     control_a(t_prmpt *prmpt);
int     control_k(t_prmpt *prmpt);

/*
** sequence.c
*/
int	special_char3(t_prmpt *prmpt, char *buff);
int     special_char2(t_prmpt *prmpt, char *buff);
int	sequence(t_prmpt *prmpt, char *buff);

/*
** alpha_num.c
*/
int	simple_add(t_prmpt *prmpt, char *buff);
int	alpha_num(t_prmpt *prmpt, char *buff);

/*
** term_params.c
*/
int	reinit_prompt(t_prmpt *prmpt);
int	term_params(struct termios *old, struct termios *new);

/*
** pre_parser.c
*/
char	*read_prompt(t_prmpt *prmpt);
char	*pre_parsing(t_prmpt *prmpt);

/*
** init.c
*/
int	free_all(t_prmpt *prmpt);
t_rec	*init_rec(void);
t_prmpt	*init_prompt(void);

#endif /* PREPARSER_H */
