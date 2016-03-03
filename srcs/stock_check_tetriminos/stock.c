/*
** stock.c for stock in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_bstetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Feb 23 17:01:48 2016 maud marel
** Last update Thu Mar  3 11:33:26 2016 maud marel
*/

#include <unistd.h>
#include "tetris.h"

int	copy_tetri(t_list_tetri *tetris, int *h, int *w, char *file)
{
  int	i;

  if (my_strlen(file) > (*w))
    (*w) = my_strlen(file);
  if ((tetris->tetrimino->tetrimino[(*h)] = malloc(sizeof(char)
						   * (my_strlen(file) + 1))) == NULL)
    exit(1);
  i = -1;
  while (file[++i] != '\0')
    {
      if (file[i] != ' ' && file[i] != '*')
	{
	  tetris->tetrimino->width = 0;
	  return (1);
	}
      tetris->tetrimino->tetrimino[(*h)][i] = file[i];
    }
  tetris->tetrimino->tetrimino[(*h)][i] = '\0';
  if (tetris->tetrimino->height - 1 > (*h))
    (*h)++;
  return (0);
}

int	check_form(t_list_tetri *tetris, int fd)
{
  char  *file;
  int   h;
  int   w;

  w = 0;
  h = 0;
  if ((tetris->tetrimino->tetrimino = malloc(sizeof(char*)
  						    * tetris->tetrimino->height)) == NULL)
    exit(1);
  while ((file = get_next_line(fd)) != NULL)
    if (copy_tetri(tetris, &h, &w, file) == 1)
      return (1);
  if (w != tetris->tetrimino->width || h != tetris->tetrimino->height - 1)
    {
      tetris->tetrimino->width = 0;
      while (get_next_line(fd) != NULL);
      return (1);
    }
  return (0);
}

int	stock_elem(t_list_tetri *tetris, int j, int i, char *f_l)
{
  if (j == 0)
    tetris->tetrimino->width = f_l[i] - 48;
  else if (j == 1)
    tetris->tetrimino->height = f_l[i] - 48;
  else
    {
      if (f_l[i] <= '0' || f_l[i] > '7')
	return (1);
      tetris->tetrimino->color = f_l[i] - 48;
    }
  return (0);
}

int	check_info(char *f_l, t_list_tetri *tetris)
{
  int   i;
  int   j;
  int	k;

  i = -1;
  j = -1;
  while (++j < 3)
    {
      k = 0;
      while (f_l[++i] != ' ' && f_l[i] != '\0')
	{
	  if (f_l[i] < 48 || f_l[i] > 57 || k++ > 1
	      || stock_elem(tetris, j, i, f_l) == 1)
	    {
	      tetris->tetrimino->width = 0;
	      return (1);
	    }
	}
      if ((f_l[i] == '\0' && j != 2) || (f_l[i] != '\0' && j == 2))
	{
	  tetris->tetrimino->width = 0;
	  return (1);
	}
    }
  return (0);
}

int	stock(char *file, t_tetris *tetris, int fd, char *name)
{
  t_list_tetri  *new;

  new = which_order(tetris, name);
  if ((new->tetrimino = malloc(sizeof(t_tetri))) == NULL)
    exit(1);
  if ((new->tetrimino->name = malloc(sizeof(char)
				     * my_strlen(name) + 1)) == NULL)
    exit(1);
  my_strcpy(new->tetrimino->name, name);
  if (check_info(file, new) != 1)
    if (check_form(new, fd) == 1)
      return (1);
  return (0);
}
