/*
** verif_size_all.c for verif_size_all in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar  4 21:14:35 2016 maud marel
** Last update Fri Mar  4 21:19:05 2016 maud marel
*/

#include <stdlib.h>
#include "tetris.h"

void	verif_size_all(t_tetris *tetris)
{
  t_list_tetri	*elem_next;

  elem_next = tetris->list_tetri->next;
  while (elem_next != tetris->list_tetri)
    {
      if (elem_next->tetrimino->height > tetris->options->row
	  || elem_next->tetrimino->width > tetris->options->col)
	{
	  my_putstr_error("Size tetrimino too big for the board\n\n");
	  display_help();
	  exit(1);
	}
      elem_next = elem_next->next;
    }
}
