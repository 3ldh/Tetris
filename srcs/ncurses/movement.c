/*
** movement.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Mar  6 18:33:26 2016 Mathieu Sauvau
** Last update Mon Mar  7 19:52:48 2016 Mathieu Sauvau
*/

#include "tetris.h"

bool		can_move_down(t_tetris *data, t_tetri *tetri)
{
  if (tetri->y + tetri->height + 1 >= data->options->row
      || space_occupied_down(data, tetri))
    return (false);
  return (true);
}

bool		can_move_left(t_tetris *data, t_tetri *tetri)
{
  int first_star;

  first_star = get_first_star_on_x(tetri);
  if (tetri->x - 1 < -first_star + 2
      || space_occupied_left(data, tetri))
    return (false);
  return (true);
}

bool		can_move_right(t_tetris *data, t_tetri *tetri)
{
  int first_star;

  first_star = get_last_star_on_x(tetri);
  if (tetri->x + first_star >= data->options->col - 2
      || space_occupied_right(data, tetri))
    return (false);
  return (true);
}

t_tetri		*rotate_tetri(t_tetri *tetri)
{
  int		x;
  int		y;
  int		x2;
  int		y2;
  int		tmp;
  char		new[tetri->max][tetri->max];

  y = -1;
  y2 = -1;
  tmp = tetri->width;
  tetri->width = tetri->height;
  tetri->height = tmp;
  while (++y < tetri->max)
    {
      x = -1;//tetri->max;
      x2 = -1;
      ++y2;
      while (++x < tetri->max)
	{
	  ++x2;
	  new[y][x] = tetri->tetrimino[tetri->max - x - 1][y];
	}
    }
  y = -1;
  while (++y < tetri->max)
    {
      x = -1;
      while (++x < tetri->max)
	tetri->tetrimino[y][x] = new[y][x];
    }
  return(tetri);
}
