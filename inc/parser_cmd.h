/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** parser_cmd
*/

#ifndef PARSER_CMD_H
# define PARSER_CMD_H

/*
** parser_cmd.c
*/
char	**parser_cmd(char *cmd, char ***env);

/*
** globbing.c
*/
char	**globbing(char **tab);
int	detect_globbing(char *str);

/*
** my_tabconcat.c
*/
char	**my_tabconcat(char **tab1, char **tab2);
int	add_elem_tab(char ***tab, char *add);

/*
** inhibitors.c
*/
int	inhibitors(char **tab);
char	*delete_inhibitors(char *str);

#endif /* !PARSER_CMD_H */
