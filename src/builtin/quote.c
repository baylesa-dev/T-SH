/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** quote
*/

#include "mysh.h"
#include "builtin.h"
#include "parser_cmd.h"

char	*my_quoteup(char *str, int *i, char sign)
{
  char	*ret;
  int	j;
  int	k;

  k = 0;
  j = *i;
  while (str[j] && str[j] != sign)
    {
      k = k + 1;
      j = j + 1;
    }
  ret = (char *)malloc(sizeof(char) * (k + 1));
  if (!ret)
    return (NULL);
  j = 0;
  while (str[*i] && str[*i] != sign)
    {
      ret[j] = str[*i];
      j = j + 1;
      *i = *i + 1;
    }
  ret[j] = '\0';
  return (ret);
}

int	check_quote(char *str, int *i, int nb, char sign)
{
  int	k;

  k = 0;
  while (str[*i] == sign && k < nb)
    {
      *i = *i + 1;
      k = k + 1;
    }
  if (k != nb)
    {
      if (sign == '\"')
        my_perror("Unmatched '\"'.\n");
      if (sign == '\'')
        my_perror("Unmatched '\''.\n");
      return (1);
    }
  return (0);
}


int	simple_quote(char *str, int *i, char ***ret)
{
  int	j;
  char	*up;

  if (str[*i] != '\'')
    return (-1);
  j = 0;
  while (str[*i] == '\'')
    {
      j = j + 1;
      *i = *i + 1;
    }
  if (!(up = my_quoteup(str, i, '\'')) || check_quote(str, i, j, '\''))
    {
      if (up)
        free(up);
      return (1);
    }
  add_elem_tab(ret, up);
  return (0);
}

int	double_quote(char *str, int *i, char ***ret, char **env)
{
  int	j;
  char	*up;

  if (str[*i] != '\"')
    return (-1);
  j = 0;
  while (str[*i] == '\"')
    {
      j = j + 1;
      *i = *i + 1;
    }
  if (!(up = my_quoteup(str, i, '\"')) || check_quote(str, i, j, '\"'))
    {
      if (up)
        free(up);
      return (1);
    }
  if (!(up = my_varconcat(up, env)))
    return (1);
  add_elem_tab(ret, up);
  return (0);
}

int	no_quote(char *str, int *i, char ***ret, char **env)
{
  int	j;
  int	k;
  char	*new;

  k = 0;
  j = *i;
  while (str[j] && str[j] != ' ' && str[j] != '\t')
    {
      k = k + 1;
      j = j + 1;
    }
  if (!(new = (char *)malloc(sizeof(char) * (k + 1))))
    return (1);
  j = 0;
  while (str[*i] && str[*i] != ' ' && str[*i] != '\t')
    {
      new[j] = str[*i];
      j = j + 1;
      *i = *i + 1;
    }
  new[j] = '\0';
  new = my_varconcat(new, env);
  add_elem_tab(ret, new);
  return (0);
}
