/*
** movement.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Mar  6 18:33:26 2016 Mathieu Sauvau
** Last update Sun Mar  6 18:35:30 2016 Mathieu Sauvau
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
  if (tetri->x - 1 <= 0
      || space_occupied_left(data, tetri))
    return (false);
  return (true);
}

bool		can_move_right(t_tetris *data, t_tetri *tetri)
{
  if (tetri->x + tetri->width + 1 >= data->options->col
      || space_occupied_right(data, tetri))
    return (false);
  return (true);
}

t_tetri		*rotate_tetri(t_tetri *tetri)
{
  int		x;
  int		y;
  int		tmp;
  char		new[tetri->max][tetri->max];

  y = -1;
  tmp = tetri->width;
  tetri->width = tetri->height;
  tetri->height = tmp;
  while (++y < tetri->max)
    {
      x = -1;
      while (++x < tetri->max)
	new[y][x] = tetri->tetrimino[tetri->max - x - 1][y];
    }
  y = -1;
  while (++y < tetri->max)
    {
      x = -1;
      while (++x < tetri->max)
	{
	  tetri->tetrimino[y][x] = new[y][x];
	}
    }
  return(tetri);
}
