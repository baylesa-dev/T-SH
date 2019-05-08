/*
** setenv.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src
**
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
**
** Started on  Sat May  6 18:20:45 2017 Varé Paul
** Last update Sun May 21 17:15:22 2017 Varé Paul
*/

#include "mysh.h"
#include "builtin.h"
#include <stdlib.h>

char	**add_env_var(char *s1, char *s2, char **env)
{
  char	**ret;
  int	i;

  ret = (char **)malloc(sizeof(char *) * (my_tablen(env) + 2));
  if (ret == NULL)
    return (NULL);
  i = 0;
  while (env[i])
    {
      ret[i] = env[i];
      i = i + 1;
    }
  ret[i] = my_envconcat(s1, s2);
  ret[i + 1] = 0;
  free(env);
  return (ret);
}

int	error_setenv_str(char **tab)
{
  int	i;

  if ((tab[1][0] < 'a' || tab[1][0] > 'z') &&
      (tab[1][0] < 'A' || tab[1][0] > 'Z'))
    {
      my_perror("setenv: Variable name must begin with a letter.\n");
      return (1);
    }
  i = 0;
  while (tab[1][i] != '\0')
    {
      if ((tab[1][i] < 'a' || tab[1][i] > 'z') &&
          (tab[1][i] < 'A' || tab[1][i] > 'Z') &&
          (tab[1][i] < '0' || tab[1][i] > '9'))
        {
          my_perror("setenv: Variable name must ");
          my_perror("contain alphanumeric characters.\n");
          return (1);
        }
      i = i + 1;
    }
  return (0);
}

int	error_setenv(char **tab)
{
  if (tab[1] && tab[2] && tab[3])
    {
      my_perror("setenv: Too many arguments.\n");
      return (1);
    }
  return (error_setenv_str(tab));
}

int	my_setenv(char **tab, char ***env, char *cmd)
{
  int	index;

  (void)cmd;
  if (!tab[1] && aff_tab(*env) == 0)
    return (0);
  if (error_setenv(tab))
    return (1);
  if ((index = find_var_env(*env, tab[1])) != -1)
    {
      free(env[0][index]);
      if (tab[2])
	env[0][index] = my_envconcat(tab[1], tab[2]);
      else
	env[0][index] = my_envconcat(tab[1], NULL);
      return (0);
    }
  else
    {
      if (tab[2])
	*env = add_env_var(tab[1], tab[2], *env);
      else
	*env = add_env_var(tab[1], NULL, *env);
    }
  return (0);
}
