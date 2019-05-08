/*
** parser_cmd.h for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/include
**
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
**
** Started on  Fri May 19 15:29:53 2017 Varé Paul
** Last update Sun May 21 17:32:54 2017 Varé Paul
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
