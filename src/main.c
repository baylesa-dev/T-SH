/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** main
*/

#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>

char	*get_pwd()
{
  char	*buf;

  buf = NULL;
  buf = getcwd(buf, 512);
  return (buf);
}

int	prompt()
{
  char	*pwd;

  pwd = get_pwd();
  if (!pwd)
    {
      my_printf("Error loading pwd\n");
      return (84);
    }
  my_printf("%s> ", pwd);
  free(pwd);
  return (0);
}

int		main_classic(char **env)
{
  int		ret;
  char		*str;

  ret = 0;
  while (42)
    {
      str = get_next_line(0);
      if (str == NULL)
	{
	  free_tab(env);
	  return (ret);
	}
      ret = parser(str, &env);
      free(str);
    }
  return (ret);
}

int		main_preparsing(char **env)
{
  t_prmpt	*prmpt;
  int		ret;
  char		*str;

  ret = 0;
  if ((prmpt = init_prompt()) == NULL)
    return (84);
  if ((term_params(&(prmpt->old_trm), &(prmpt->new_trm))) != 0)
    return (84);
  tcsetattr(0, TCSANOW, &prmpt->new_trm);
  while (42)
    {
      prompt();
      str = pre_parsing(prmpt);
      if (str == NULL)
	{
	  free_tab(env);
	  return (ret);
	}
      ret = parser(str, &env);
      reinit_prompt(prmpt);
    }
  free_all(prmpt);
  return (0);
}

int	main(int ac, char **av, char **env)
{
  char	**envp;
  int   ret;

  (void)ac;
  (void)av;
  if ((envp = cp_env(env)) == NULL)
    return (84);
  if (isatty(0))
    ret = main_preparsing(envp);
  else
    ret = main_classic(envp);
  return (ret);
}
