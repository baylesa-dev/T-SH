/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** get_next_line
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

char	*my_strconcat(char *s1, char *s2)
{
  char	*ret;
  int	i;
  int	j;

  ret = (char *)malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
  if (!ret)
    return (NULL);
  i = 0;
  j = 0;
  while (s1 && s1[i])
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

int	search_bse(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	return (i);
      i = i + 1;
    }
  return (-1);
}

int	cut_str(char **tmp, char **str)
{
  int	index;
  char	*new;
  int	i;

  if ((index = search_bse(*tmp)) == -1)
    return (0);
  (*str ? free(*str) : 0);
  if (tmp[0][index + 1])
    *str = my_strdup(&tmp[0][index + 1]);
  else
    *str = NULL;
  if ((new = (char *)malloc(sizeof(char) * (index + 1))) == NULL)
    return (84);
  i = 0;
  while (i < index)
    {
      new[i] = tmp[0][i];
      i = i + 1;
    }
  new[i] = '\0';
  free(*tmp);
  *tmp = new;
  return (1);
}

char		*get_next_line(const int fd)
{
  static char	*str = NULL;
  char		buf[READ_SIZE];
  int		ret;
  char		*tmp;

  tmp = NULL;
  if (str)
    {
      if (!(tmp = my_strconcat(tmp, str)) || (ret = cut_str(&tmp, &str)) == 84)
        return (NULL);
      if (ret == 1)
        return (tmp);
    }
  while ((ret = read(fd, buf, READ_SIZE)))
    {
      if (ret == -1)
	return (NULL);
      buf[ret] = '\0';
      tmp = my_strconcat(tmp, buf);
      if (tmp == NULL || (ret = cut_str(&tmp, &str)) == 84)
	return (NULL);
      if (ret == 1)
	return (tmp);
    }
  return (tmp);
}
