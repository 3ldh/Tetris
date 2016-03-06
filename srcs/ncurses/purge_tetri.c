/*
** purge_tetri.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Mar  6 18:46:31 2016 Mathieu Sauvau
** Last update Sun Mar  6 18:46:57 2016 Mathieu Sauvau
*/

#include "tetris.h"

t_list_tetri	*get_valid_tetri(t_list_tetri *all_tetri)
{
  t_list_tetri	*valid;
  int		n;

  valid = all_tetri->next;
  while (valid != all_tetri)
    {
      if (valid->tetrimino->width == 0)
	{
	  valid->prev->next = valid->next;
	  valid->next->prev = valid->prev;
	}
      valid = valid->next;
    }
  return (valid);
}

void		center_tetri(t_list_tetri *list_tetri)
{
  t_list_tetri	*elem_next;
  int		x;
  int		y;

  elem_next = list_tetri->next;
  while (elem_next != list_tetri)
    {
      y = -1;
      if (elem_next->tetrimino->width != elem_next->tetrimino->height)
	{
	  while (++y < elem_next->tetrimino->max)
	    {
	      x = -1;
	      while (++x < elem_next->tetrimino->max)
		{
		  /* if (elem_next->tetrimino->width == elem_next->tetrimino->max */
		  /*     && y < elem_next->tetrimino->max / 2 */
		  /*     && elem_next->tetrimino->max % 2 == 0) */
		  /*   { */
		  /*     elem_next->tetrimino->tetrimino[y + elem_next->tetrimino->max / 2][x] */
		  /* 	= elem_next->tetrimino->tetrimino[y][x]; */
		  /*     elem_next->tetrimino->tetrimino[y][x] = ' '; */
		  /*     elem_next->tetrimino->y = -elem_next->tetrimino->max / 2; */
		  /*   } */
		  /* else if (elem_next->tetrimino->height == elem_next->tetrimino->max */
		  /* 	   && x < elem_next->tetrimino->max / 2 */
		  /* 	   && elem_next->tetrimino->max % 2 == 0) */
		  /*   { */
		  /*     elem_next->tetrimino->tetrimino[y][x + elem_next->tetrimino->max / 2] */
		  /* 	= elem_next->tetrimino->tetrimino[y][x]; */
		  /*     elem_next->tetrimino->tetrimino[y][x] = ' '; */
		  /*     elem_next->tetrimino->x = -elem_next->tetrimino->max / 2; */
		  /*   } */
		  if (elem_next->tetrimino->tetrimino[y][x] != '*')
		    elem_next->tetrimino->tetrimino[y][x] = ' ';
		}
	    }
	}
      elem_next = elem_next->next;
    }
}
