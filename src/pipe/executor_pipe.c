/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** executor_pipe
*/

#include "mysh.h"
#include "pipe.h"
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int		exec_for_pipe(char **tab, char ***env, char *cmd)
{
  int		ret;
  t_list	*path;

  ret = 0;
  if ((ret = builtin(tab, env, cmd)) != -1)
    return (ret);
  path = get_path(*env);
  ret = process_child(path, tab, *env);
  return (ret);
}

int	exec_redirection(char **tab, t_table *table, char ***env)
{
  int	ret;

  ret = 0;
  if (table->redirec == 3)
    ret = g_one_chevron(tab, table->input, env, table);
  if (table->redirec == 4)
    ret = g_double_chevron(tab, table->input, env, table);
  if (table->redirec == 1)
    ret = d_one_chevron(tab, table->output, env, table);
  if (table->redirec == 2)
    ret = d_double_chevron(tab, table->output, env, table);
  return (ret);
}

int	one_cmd(t_table *table, char ***env)
{
  char	**tab;
  int	ret;

  tab = 0;
  if (table->cmd)
    return (execution(table->cmd, env));
  if (table->redirec > 2)
    tab = my_str_to_wordtab(table->output);
  else
    tab = my_str_to_wordtab(table->input);
  ret = exec_redirection(tab, table, env);
  if (tab)
    free_tab(tab);
  return (ret);
}

int	sig_error(t_list *table)
{
  t_list	*path;
  int		ret;
  t_table	*s_table;
  t_table	*tmp;

  tmp = NULL;
  ret = 0;
  path = table;
  while (path)
    {
      s_table = path->data;
      waitpid(s_table->pid, &s_table->status, 0);
      if (WIFEXITED(s_table->status) && WEXITSTATUS(s_table->status))
	ret = WEXITSTATUS(s_table->status);
      else if (WIFSIGNALED(s_table->status) && !tmp)
	tmp = s_table;
      path = path->next;
    }
  if (tmp)
    ret = sig_term(tmp->status);
  return (ret);
}

int		executor_pipe(t_list *table, char ***env)
{
  t_list	*path;
  t_table	*s_table;
  int		pipefd[2];
  int		pipefd2[2];

  path = table;
  if (!path->next)
    return (one_cmd(path->data, env));
  s_table = path->data;
  if (pipe(pipefd) == -1)
    return (1);
  if (start_multi_pipe(s_table, pipefd, env))
    return (1);
  path = path->next;
  if (multi_pipe(&path, pipefd, pipefd2, env) == 1)
    return (1);
  s_table = path->data;
  if (end_multi_pipe(s_table, pipefd, env))
    return (1);
  return (sig_error(table));
}
