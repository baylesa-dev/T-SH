/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** auto_complete
*/

#include "preparser.h"
#include <dirent.h>
#include <stdio.h>

char	*my_strtrickconcat(char *s1, char *s2, int pos)
{
  char  *ret;
  int   i;
  int   j;

  ret = (char *)malloc(sizeof(char) * (pos + my_strlen(s2) + 1));
  if (!ret)
    return (NULL);
  i = 0;
  j = 0;
  while (s1 && s1[i] && i < pos)
    {
      ret[j] = s1[i];
      j = j + 1;
      i = i + 1;
    }
  i = 0;
  while (s2 && s2[i])
    {
      ret[j] = s2[i];
      j = j + 1;
      i = i + 1;
    }
  ret[j] = '\0';
  (s1 ? free(s1) : 0);
  return (ret);
}

int	display_multi(t_prmpt *prmpt, char **tab)
{
  int	i;
  int	max;

  i = 0;
  max = get_lenght_max(tab);
  write(1, "\n", 1);
  while (tab[i])
    {
      printf("%-*s", max + 2, tab[i++]);
      if (i % 3 == 0)
	printf("\n");
    }
  printf("\n");
  clean_line(prmpt);
  my_printf("%s> %s", get_pwd(), prmpt->cmd);
  prmpt->pos = my_strlen(prmpt->cmd);
  prmpt->max_p = my_strlen(prmpt->cmd);
  return (0);
}

int	display_one(t_prmpt *prmpt, char **tab, int pos)
{
  if (prmpt->cmd)
    prmpt->old_cmd = my_strdup(prmpt->cmd);
  clean_line(prmpt);
  prmpt->cmd = my_strtrickconcat(prmpt->cmd, tab[0], pos);
  write(1, prmpt->cmd, my_strlen(prmpt->cmd));
  prmpt->pos = my_strlen(prmpt->cmd);
  prmpt->max_p = my_strlen(prmpt->cmd);
  return (0);
}

char		**get_files(char *str)
{
  int		i;
  char		**tab;
  struct dirent	**list;

  tab = NULL;
  if ((i = scandir(".", &list, NULL, alphasort)) < 0)
    return (NULL);
  else
    {
      while (i--)
	{
	  if ((my_strncmp(list[i]->d_name, str, my_strlen(str))) == 0)
	    tab = add_to_tab(list[i]->d_name, tab);
	  free(list[i]);
	}
      free(list);
    }
  return (tab);
}

int		auto_complete(t_prmpt *prmpt)
{
  int           i;
  char          **occur;

  i = 0;
  while (prmpt->cmd[i] && prmpt->cmd[i] != ' ')
    i++;
  if (i == my_strlen(prmpt->cmd))
    occur = get_files(prmpt->cmd);
  else
    occur = get_files(prmpt->cmd + i + 1);
  if (!occur)
    return (84);
  else if (my_len(occur) == 2)
    return (display_one(prmpt, occur, i + 1));
  else
    return (display_multi(prmpt, occur));
  return (0);
}
