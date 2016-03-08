/*
** purge_tetri.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Mar  6 18:46:31 2016 Mathieu Sauvau
** Last update Tue Mar  8 14:17:41 2016 Mathieu Sauvau
*/

#include "tetris.h"

t_list_tetri	*get_valid_tetri(t_list_tetri *all_tetri)
{
  t_list_tetri	*valid;

  valid = all_tetri->next;
  while (valid != all_tetri)
    {
      if (valid->tetrimino->width == 0)
	{
	  valid->prev->next = valid->next;
	  valid->next->prev = valid->prev;
	  free(valid->tetrimino->name);
	  free(valid->tetrimino);
	  /* free(valid); */
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
      printf("%s\n",elem_next->tetrimino->name);
      printf("max %d\n",elem_next->tetrimino->max);
	  while (++y < elem_next->tetrimino->max)
	    {
	      x = -1;
	      while (++x < elem_next->tetrimino->max)
		{
		  printf("y %d x %d\n", y, x);
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
      elem_next = elem_next->next;
    }
}
