/*
** execution.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src
**
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
**
** Started on  Fri May  5 13:03:10 2017 Varé Paul
** Last update Sun May 21 17:17:50 2017 Alexandre CAUSSADE
*/

#include "mysh.h"
#include "builtin.h"
#include "parser_cmd.h"
#include <stdlib.h>

char	**get_corres_tab()
{
  char  **ret;

  ret = (char **)malloc(sizeof(char *) * 10);
  if (ret == NULL)
    return (NULL);
  ret[0] = my_strdup("echo");
  ret[1] = my_strdup("env");
  ret[2] = my_strdup("setenv");
  ret[3] = my_strdup("unsetenv");
  ret[4] = my_strdup("cd");
  ret[5] = my_strdup("exit");
  ret[6] = my_strdup("repeat");
  ret[7] = my_strdup("where");
  ret[8] = my_strdup("which");
  ret[9] = NULL;
  return (ret);
}

int	(**get_fptr(void))(char **tab, char ***env, char *cmd)
{
  int   (**ret)(char **tab, char ***env, char *cmd);

  ret = malloc(sizeof(*ret) * 10);
  if (ret == NULL)
    return (NULL);
  ret[0] = echo;
  ret[1] = aff_env;
  ret[2] = my_setenv;
  ret[3] = my_unsetenv;
  ret[4] = cd;
  ret[5] = my_exit;
  ret[6] = repeat;
  ret[7] = where;
  ret[8] = which;
  ret[9] = NULL;
  return (ret);
}

int	builtin(char **tab, char ***env, char *cmd)
{
  int   (**f_ptr)(char **tab, char ***env, char *cmd);
  char	**corres;
  int	i;
  int	ret;

  if (!(f_ptr = get_fptr()) || !(corres = get_corres_tab()))
    return (1);
  i = 0;
  while (corres[i])
    {
      if (my_strcmp(tab[0], corres[i]) == 0)
	{
	  ret = f_ptr[i](tab, env, cmd);
	  free_tab(corres);
	  free(f_ptr);
	  return (ret);
	}
      i = i + 1;
    }
  free_tab(corres);
  free(f_ptr);
  if (my_strncmp(tab[0], "$", 1) == 0 && tab[0][1])
    return (var_interpreted(tab, env));
  return (-1);
}

int	execution(char *cmd, char ***env)
{
  char	**tab_cmd;
  int	ret;

  tab_cmd = parser_cmd(cmd, env);
  if (!tab_cmd)
    return (1);
  if ((ret = builtin(tab_cmd, env, cmd)) == -1)
    ret = exec_command(tab_cmd, *env);
  free_tab(tab_cmd);
  return (ret);
}
