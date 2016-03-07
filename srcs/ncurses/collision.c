/*
** collision.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Mar  6 18:35:45 2016 Mathieu Sauvau
** Last update Mon Mar  7 19:58:21 2016 Mathieu Sauvau
*/

#include "tetris.h"

int		get_last_star_on_y(t_tetri *tetri)
{
  int		x;
  int		y;

  y = tetri->max;
  while(--y >= 0)
    {
      x = -1;
      while(++x < tetri->max)
	{
	  if (tetri->tetrimino[y][x] == '*')
	    return (y);
	}
    }
  return (0);
}

int		get_first_star_on_x(t_tetri *tetri)
{
  int		x;
  int		y;

  y = -1;
  while(++y < tetri->max)
    {
      x = -1;
      while(++x < tetri->max)
	{
	  if (tetri->tetrimino[x][y] == '*')
	    return (y + 1);
	}
    }
  return (0);
}

int		get_last_star_on_x(t_tetri *tetri)
{
  int		x;
  int		y;

  x = tetri->max;
  while(--x >= 0)
    {
      y = -1;
      while(++y < tetri->max)
	{
	  if (tetri->tetrimino[y][x] == '*')
	    return (x);
	}
    }
  return (0);
}

bool		space_occupied_down(t_tetris *data, t_tetri *tetri)
{
  int		x;
  int		y;
  int		last_star;

  y = -1;
  last_star = get_last_star_on_y(tetri);
  while (++y < tetri->max)
    {
      x = -1;
      while (++x < tetri->max)
	{
	  if (tetri->y + y >= 20 && last_star == tetri->max - 1)
	    return (true);
	  if (tetri->y > 0
	      && tetri->tetrimino[y][x] == '*'
	      && data->board[y + tetri->y][x + tetri->x - 1] != 0)
	    return (true);
	}
    }
  return (false);
}

bool		space_occupied_right(t_tetris *data, t_tetri *tetri)
{
  int		x;
  int		y;

  y = -1;
  while (++y < tetri->max)
    {
      x = -1;
      while (++x < tetri->max)
	if (tetri->y > 0 && tetri->tetrimino[y][x] == '*'
	    && data->board[y + tetri->y - 1][x + tetri->x] != 0)
	  return (true);
    }
  return (false);
}

bool		space_occupied_left(t_tetris *data, t_tetri *tetri)
{
  int		x;
  int		y;

  y = -1;
  while (++y < tetri->max)
    {
      x = -1;
      while (++x < tetri->max)
	{
	  if (tetri->y > 0 && tetri->tetrimino[y][x] == '*'
	      && data->board[y + tetri->y - 1][x + tetri->x - 2] != 0)
	    return (true);
	}
    }
  return (false);
}
