/*
** EPITECH PROJECT, 2017
** T-SH
** File description:
** sequence
*/

#include "preparser.h"

int	special_char3(t_prmpt *prmpt, char *buff)
{
  char	tab[5];
  int	(*func[5])(t_prmpt*);
  int	i;

  i = 0;
  tab[0] = 51;
  tab[1] = 'D';
  tab[2] = 'C';
  tab[3] = 'A';
  tab[4] = 'B';
  func[0] = delete_key;
  func[1] = cursor_left;
  func[2] = cursor_right;
  func[3] = record_up;
  func[4] = record_down;
  while (i < 5)
    {
      if (tab[i] == buff[2])
	return (func[i](prmpt));
      i++;
    }
  return (0);
}

int	special_char2(t_prmpt *prmpt, char *buff)
{
  if (buff[0] == 0x09 && prmpt->pos > 0)
    auto_complete(prmpt);
  else
    special_char3(prmpt, buff);
  return (0);
}

int	sequence(t_prmpt *prmpt, char *buff)
{
  char	tab[6];
  int	(*func[6])(t_prmpt*);
  int	i;

  i = 0;
  tab[0] = 0x0C;
  tab[1] = 0x04;
  tab[2] = 0x03;
  tab[3] = 0x01;
  tab[4] = 0x0B;
  tab[5] = prmpt->new_trm.c_cc[VERASE];
  func[0] = clear_screen;
  func[1] = control_d;
  func[2] = control_c;
  func[3] = control_a;
  func[4] = control_k;
  func[5] = erase_char;
  while (i < 6)
    {
      if (tab[i] == buff[0])
	return (func[i](prmpt));
      i++;
    }
  special_char2(prmpt, buff);
  return (0);
}
