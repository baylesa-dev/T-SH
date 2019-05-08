/*
** pipe.h for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/include
**
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
**
** Started on  Sun May  7 15:30:40 2017 Varé Paul
** Last update Sun May 21 17:32:38 2017 Varé Paul
*/

#ifndef PIPE_H
# define PIPE_H

#include <unistd.h>

typedef struct	s_table
{
  char		*cmd;
  int		pid;
  int		status;
  char		redirec;
  char		*input;
  char		*output;
}		t_table;

/*
** parser_pipe.c
*/
int	parser_pipe(char *cmd, char ***env);

/*
** list_pipe.c
*/
t_list	*list_pipe(char *str);

/*
** command_table.c
*/
t_list	*parser_table(t_list *list);

/*
** executor_pipe.c
*/
int	executor_pipe(t_list *table, char ***env);
int	exec_for_pipe(char **tab, char ***env, char *cmd);

/*
** redirections_left.c
*/
int     g_one_chevron(char **cmd, char *name, char ***env, t_table *table);
int     g_double_chevron(char **cmd, char *name, char ***env, t_table *table);
int	check_error_fd(int code, char *name);
int	write_line_pipe(char *name, int pipefd[2]);

/*
** redirections_right.c
*/
int	d_one_chevron(char **cmd, char *name, char ***env, t_table *table);
int	d_double_chevron(char **cmd, char *name, char ***env, t_table *table);

/*
** pipe_rw.c
*/
int	write_pipe(char *cmd, char ***env, int pipefd[2], pid_t *f_pid);
int	rw_pipe(t_table *table, char ***env, int pipefd[2], int pipefd2[2]);
int	read_pipe(char *cmd, char ***env, int pipefd[2], pid_t *f_pid);

/*
** redirections_left_pipe.c
*/
int	g_one_chevron_pipe(t_table *s_table, char ***env, int pipefd[2]);
int	g_double_chevron_pipe(t_table *s_table, char ***env, int pipefd2[2]);

/*
** redirections_right_pipe.c
*/
int	d_one_chevron_pipe(t_table *s_table, char ***env, int pipefd[2]);
int     d_one_chevron_out(t_table *s_table, int pipefd[2]);
int     d_double_chevron_pipe(t_table *s_table, char ***env, int pipefd[2]);
int	d_double_chevron_out(t_table *s_table, int pipefd[2]);

/*
** lexer_pipe.c
*/
int	lexer_pipe(t_list *list);
int	lexer_redirections(t_list *table);

/*
** cut_redirections.c
*/
t_list	*cut_redirection(char *cmd);
t_list	*insert_cut_str(char *str, int len, t_list **list);
int	detect_redirection(char *cmd);

/*
** get_input.c
*/
char	*get_input(char *str);

/*
** get_output.c
*/
char	*get_ouput(char *str);

/*
** swap_ptr.c
*/
void	swap_ptr(char **p1, char **p2);

/*
** process_pipe.c
*/
int	is_a_cmd(char *str);
int	multi_pipe(t_list **path, int pipefd[2],
                   int pipefd2[2], char ***env);
int	start_multi_pipe(t_table *s_table, int pipefd[2], char ***env);
int	end_multi_pipe(t_table *s_table, int pipefd[2], char ***env);

#endif /* !PIPE_H */
