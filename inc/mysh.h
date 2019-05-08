/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** mysh
*/

#ifndef MYSH_H
# define MYSH_H

#include "my.h"
#include "preparser.h"

/*
** main.c
*/
char	*get_pwd();
int	prompt();

/*
** parser.c
*/
int	parser(char *cmd, char ***env);

/*
** parser_semi_colon.c
*/
t_list	*semi_colon(char *str);

/*
** free.c
*/
void	free_list(t_list *list);
void	free_tab(char **tab);
void	free_3tab(char ***tab);
void	free_list_table(t_list *list);

/*
** list_binary_opt.c
*/
t_list	*binary_opt(char *cmd);
int	check_empty_cmd(char *str, int *index, int len);

/*
** execution.c
*/
int	execution(char *cmd, char ***env);
int	builtin(char **tab, char ***env, char *cmd);
char	**get_corres_tab();

/*
** exec_command.c
*/
int	exec_command(char **tab, char **env);
int     process_child(t_list *path, char **tab, char **env);
int	sig_term(int status);

/*
** my_str_to_wordtab.c
*/
char	**my_str_to_wordtab(char *str);

/*
** get_path.c
*/
t_list	*get_path(char **env);
int	find_var_env(char **env, char *cmp);

/*
** my_spconcat.c
*/
char	*my_pathconcat(char *s1, char *s2);
char	*my_envconcat(char *s1, char *s2);

/*
** copy_env.c
*/
char	**cp_env(char **env);

/*
** parser_binary_opt.c
*/
int	valid_binary_opt_and(t_list *list);
int	valid_binary_opt_or(t_list *list);
int	perform_binary_opt(t_list *list, char ***env);
int	parser_binary_opt(char *cmd, char ***env);

#endif /* !MYSH_H */
