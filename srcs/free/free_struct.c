/*
** free_struct.c for free_struct in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_tetris/srcs/free
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Sun Mar  6 15:15:50 2016
** Last update Tue Mar  8 09:02:34 2016 maud marel
*/

#include "tetris.h"

void	free_tetri(t_list_tetri *tetris)
{
  int	i;

  i = 0;
  if (tetris->tetrimino->width != 0)
    while (i < tetris->tetrimino->max)
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
      free(delete->prev->tetrimino->name);
      free_tetri(delete->prev);
      free(delete->prev->tetrimino);
      free(delete->prev);
    }
  free(tetris->list_tetri);
}
