/*
** change_map_size.c for change_map_size in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:46:17 2016 maud marel
** Last update Tue Mar  1 22:47:53 2016 maud marel
*/

#include "tetris.h"

void	change_map_size(t_tetris *tetris, char *str)
{
  int   i;
  int   j;
  char	*tmp;
  int	nb;

  i = 0;
  while (str && str[i] != '=')
    i++;
  i++;
  if (i == my_strlen(str))
    {
      write(2, "Wrong arg: --map-size={row,col}\n", 32);
      exit(1);
    }
  j = i;
  nb = 0;
  while (str[i] != ',')
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  write(2, "Wrong arg: --map-size={row,col}\n", 32);
	  exit(1);
	}
      i++;
      nb++;
    }
  if ((tmp = malloc(sizeof(char) * (nb + 1))) == NULL)
    exit(1);
  i = j;
  j = 0;
  while (str[i] != ',')
    tmp[j++] = str[i++];
  tmp[j] = '\0';
  tetris->options->row = my_getnbr(tmp);
  i++;
  j = i;
  nb = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  write(2, "Wrong arg: --map-size={row,col}\n", 32);
	  exit(1);
	}
      i++;
      nb++;
    }
  if ((tmp = malloc(sizeof(char) * (nb + 1))) == NULL)
    exit(1);
  i = j;
  j = 0;
  while (str[i] != '\0')
    tmp[j++] = str[i++];
  tmp[j] = '\0';
  tetris->options->col = my_getnbr(tmp);
}
