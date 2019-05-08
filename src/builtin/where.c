/*
** my_builting.c for my_builting in /home/alexcoss/PSU_semestre2/PSU_2016_42sh/src/where
**
** Made by Alexandre CAUSSADE
** Login   <alexcoss@epitech.net>
**
** Started on  Thu May 18 14:22:35 2017 Alexandre CAUSSADE
** Last update Sun May 21 17:17:32 2017 Varé Paul
*/

#include "mysh.h"
#include "builtin.h"
#include <stdlib.h>

int	is_bultin(char *str)
{
  int	i;
  char	**tab_builtin;

  tab_builtin = get_corres_tab();
  i = 0;
  while (tab_builtin[i])
    {
      if (my_strcmp(str, tab_builtin[i]) == 0)
	return (0);
      i++;
    }
  free_tab(tab_builtin);
  return (1);
}

char	*wh_my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*str3;

  i = 0;
  j = 0;
  str3 = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 2));
  if (!str3)
    return (NULL);
  while (dest[i] != '\0')
    {
      str3[i] = dest[i];
      i++;
    }
  str3[i] = '/';
  i++;
  while (src[j] != '\0')
    {
      str3[i] = src[j];
      i++;
      j++;
    }
  str3[i] = '\0';
  return (str3);
}

int		perform_where(char **env, char *cmd)
{
  t_list	*path;
  t_list	*save;
  char		*str;

  path = get_path(env);
  save = path;
  while (path)
    {
      if (access((str = wh_my_strcat((char *)path->data, cmd)), X_OK) == 0)
	{
	  if (str)
	    {
	      my_printf("%s\n", str);
	      free(str);
	    }
	}
      else
	{
	  if (str)
	    free(str);
	}
      path = path->next;
    }
  free_list(save);
  return (0);
}

int	where(char **tab, char ***env, char *cmd)
{
  int	i;

  (void)cmd;
  i = 1;
  if (!tab[1])
    my_printf("Where: Too few arguments.\n");
  else
    {
      while (tab[i])
	{
	  if (is_bultin(tab[i]) == 0)
	    {
	      my_printf("%s is a shell built-in\n", tab[i]);
	      i++;
	    }
	  else
	    {
	      perform_where(*env, tab[i]);
	      i++;
	    }
	}
    }
  return (1);
}
