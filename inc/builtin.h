/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** builtin
*/

#ifndef BUILTIN_H
# define BUILTIN_H

/*
** setenv.c
*/
int     my_setenv(char **tab, char ***env, char *cmd);

/*
** unsetenv.c
*/
int	my_unsetenv(char **tab, char ***env, char *cmd);

/*
** cd.c
*/
int	cd(char **tab, char ***env, char *cmd);

/*
** exit.c
*/
int	my_exit(char **tab, char ***env, char *cmd);

/*
** tab.c
*/
int	my_tablen(char **tab);
int	aff_tab(char **tab);
int	aff_env(char **tab, char ***env, char *cmd);

/*
** echo.c
*/
int	echo(char **tab, char ***env, char *cmd);

/*
** my_varconcat.c
*/
char	*my_varconcat(char *str, char **env);

/*
** repeat.c
*/
int	repeat(char **tab, char ***env, char *cmd);
int	is_a_number(char *str);

/*
** var_interpreted.c
*/
int	var_interpreted(char **tab, char ***env);

/*
** my_dollarconcat.c
*/
char	*my_dollarconcat(char *s1, char *s2);

/*
** where.c
*/
int	where(char **tab, char ***env, char *cmd);
int	perform_where(char **env, char *cmd);
int	is_bultin(char *str);

/*
** which.c
*/
int	which(char **tab, char ***env, char *cmd);

/*
** quote.c
*/
int	no_quote(char *str, int *i, char ***ret, char **env);
int	double_quote(char *str, int *i, char ***ret, char **env);
int	simple_quote(char *str, int *i, char ***ret);

#endif /* !BUILTIN_H */
