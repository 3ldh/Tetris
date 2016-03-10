/*
** free_struct.c for free_struct in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_tetris/srcs/free
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Sun Mar  6 15:15:50 2016
** Last update Wed Mar  9 14:08:34 2016 Mathieu Sauvau
*/

#include "tetris.h"

void	free_tetri(t_tetri *tetri)
{
  int	i;

  i = 0;
  if (tetri)
    {
      free(tetri->name);
      if (tetri->width != 0)
	{
	  while (i < tetri->max)
	    {
	      free(tetri->tetrimino[i]);
	      i++;
	    }
	  free(tetri->tetrimino);
	}
      free(tetri);
    }
}

void			free_list_tetri(t_tetris *tetris)
{
  t_list_tetri		*delete;

  delete = tetris->list_tetri->next;
  while (delete != tetris->list_tetri)
    {
      delete = delete->next;
      free_tetri(delete->prev->tetrimino);
      free(delete->prev);
    }
  free(tetris->list_tetri);
}

void			free_board(t_tetris *tetris)
{
  int			y;

  y = -1;
  while (++y < tetris->options->row - 2)
    free(tetris->board[y]);
  free(tetris->board);
}

void			free_struct(t_tetris *tetris)
{
  free_list_tetri(tetris);
  delwin(tetris->wgame);
  delwin(tetris->wscore);
  delwin(tetris->wnext);
  free_board(tetris);
  free_options(tetris);
  free(tetris->key_tab);
}
