/*
** process_pipe.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src/pipe
** 
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
** 
** Started on  Tue May 16 17:04:09 2017 Varé Paul
** Last update Sun May 21 15:12:01 2017 Adrien Bayles
*/

#include "mysh.h"
#include "pipe.h"

int	is_a_cmd(char *str)
{
  int   i;

  if (!str)
    return (0);
  i = 0;
  while (str[i])
    {
      if (str[i] != ' ')
        return (1);
      i = i + 1;
    }
  return (0);
}

int		multi_pipe(t_list **path, int pipefd[2],
                           int pipefd2[2], char ***env)
{
  t_table       *s_table;

  while (*path && path[0]->next)
    {
      s_table = path[0]->data;
      if (pipe(pipefd2) == -1)
        return (1);
      rw_pipe(s_table, env, pipefd, pipefd2);
      if (pipe(pipefd) == -1)
	return (1);
      pipefd[0] = pipefd2[0];
      pipefd[1] = pipefd2[1];
      *path = path[0]->next;
    }
  return (0);
}

int	start_multi_pipe(t_table *s_table, int pipefd[2], char ***env)
{
  if (s_table->cmd)
    {
      if (write_pipe(s_table->cmd, env, pipefd, &s_table->pid))
        return (1);
      return (0);
    }
  if (s_table->redirec == 3)
    g_one_chevron_pipe(s_table, env, pipefd);
  if (s_table->redirec == 4)
    g_double_chevron_pipe(s_table, env, pipefd);
  return (0);
}

int	end_multi_pipe(t_table *s_table, int pipefd[2], char ***env)
{
  if (s_table->cmd)
    {
      if (read_pipe(s_table->cmd, env, pipefd, &s_table->pid))
        return (1);
      return (0);
    }
  if (s_table->redirec == 1 && is_a_cmd(s_table->input))
    d_one_chevron_pipe(s_table, env, pipefd);
  if (s_table->redirec == 1 && !is_a_cmd(s_table->input))
    d_one_chevron_out(s_table, pipefd);
  if (s_table->redirec == 2 && is_a_cmd(s_table->input))
    d_double_chevron_pipe(s_table, env, pipefd);
  if (s_table->redirec == 2 && !is_a_cmd(s_table->input))
    d_double_chevron_out(s_table, pipefd);
  return (0);
}
