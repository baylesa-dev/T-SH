/*
** globbing.c for  in /home/paul.vare/semestre2/PSU/PSU_2016_42sh/src/parser_cmd
** 
** Made by Varé Paul
** Login   <paul.vare@epitech.net>
** 
** Started on  Fri May 19 16:23:50 2017 Varé Paul
** Last update Fri May 19 21:19:28 2017 Varé Paul
*/

#include "mysh.h"
#include "parser_cmd.h"
#include <stdlib.h>
#include <glob.h>

int	detect_globbing(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '*' && (i == 0 || (i > 0 && str[i - 1] != '\\')))
	return (1);
      if (str[i] == '?' && (i == 0 || (i > 0 && str[i - 1] != '\\')))
	return (1);
      if (str[i] == '[' && (i == 0 || (i > 0 && str[i - 1] != '\\')))
	return (1);
      i = i + 1;
    }
  return (0);
}

int	error_glob(int ret, char *prog_name, char **tab, glob_t *glob)
{
  if (ret == GLOB_NOMATCH)
    {
      my_perror(prog_name);
      my_perror(": No match.\n");
    }
  globfree(glob);
  free_tab(tab);
  return (1);
}

char		**get_glob(char **tab, char *prog_name)
{
  glob_t	res;
  int		flags;
  int		i;
  int		ret;
  char		**tab_ret;

  flags = 0;
  i = 0;
  while (tab[i])
    {
      if (i > 0)
	flags |= GLOB_APPEND;
      ret = glob(tab[i], flags, NULL, &res);
      if (ret != 0 && error_glob(ret, prog_name, tab, &res))
	return (NULL);
      i = i + 1;
    }
  if (res.gl_pathv)
    tab_ret = cp_env(res.gl_pathv);
  globfree(&res);
  free_tab(tab);
  return (tab_ret);
}

char	**globbing(char **tab)
{
  int	i;
  char	**glob;
  char	**new;

  new = NULL;
  glob = NULL;
  i = 0;
  while (tab[i])
    {
      if (detect_globbing(tab[i]))
	add_elem_tab(&glob, my_strdup(tab[i]));
      else
	add_elem_tab(&new, my_strdup(tab[i]));
      i = i + 1;
    }
  if (glob)
    glob = get_glob(glob, tab[0]);
  free_tab(tab);
  if (glob)
    return (glob = my_tabconcat(new, glob));
  if (new)
    free_tab(new);
  return (0);
}
