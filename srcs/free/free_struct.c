/*
** free_struct.c for free_struct in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_tetris/srcs/free
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Sun Mar  6 15:15:50 2016
** Last update Sun Mar  6 16:10:56 2016 
*/

#include "tetris.h"

void	free_tetri(t_list_tetri *tetris)
{
  int	i;

  free(tetris->tetrimino->name);
  i = 0;
  if (tetris->tetrimino->width != 0)
    while (i < tetris->tetrimino->width || i < tetris->tetrimino->height)
      {
	free(tetris->tetrimino->tetrimino[i]);
	i++;
      }
}

void			free_struct(t_tetris *tetris)
{
  t_list_tetri		*delete;

  delete = tetris->list_tetri->next;
  while (delete != tetris->list_tetri)
    {
      delete = delete->next;
      free_tetri(delete->prev);
      free(delete->prev);
    }
  free(tetris->list_tetri);
}
