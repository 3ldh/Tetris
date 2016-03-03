/*
** display_debug.c for display_debug in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:25:57 2016 maud marel
** Last update Thu Mar  3 13:31:35 2016 maud marel
*/

#include <unistd.h>
#include "tetris.h"

void	display_key(t_tetris *tetris)
{
  write(1, "Key Left : ", 11);
  my_putchar(tetris->options->left);
  write(1, "\n", 1);
  write(1, "Key Right : ", 12);
  my_putchar(tetris->options->right);
  write(1, "\n", 1);
  write(1, "Key Turn : ", 11);
  my_putchar(tetris->options->turn);
  write(1, "\n", 1);
  write(1, "Key Drop : ", 11);
  my_putchar(tetris->options->drop);
  write(1, "\n", 1);
  write(1, "Key Quit : ", 11);
  my_putchar(tetris->options->quit);
  write(1, "\n", 1);
  write(1, "Key Pause : ", 12);
  my_putchar(tetris->options->pause);
  write(1, "\n", 1);
}

void	display_more_info(t_tetris *tetris)
{
  write(1, "Next : ", 7);
  if (tetris->options->hide_next == 0)
    write(1, "Yes", 3);
  else
    write(1, "No", 2);
  write(1, "\n", 1);
  write(1, "Level : ", 8);
  my_put_nbr(tetris->options->level);
  write(1, "\n", 1);
  write(1, "Size : ", 7);
  my_put_nbr(tetris->options->row - 2);
  write(1, "*", 1);
  my_put_nbr(tetris->options->col - 2);
  write(1, "\n", 1);
  write(1, "Tetriminos : ", 13);
  my_put_nbr(tetris->list_tetri->nb_tetri);
  my_putchar('\n');
}

void	print_tetriminos(t_list_tetri *tetris)
{
  int	i;

  i = -1;
  write(1, "Tetriminos : Name ", 18);
  while (tetris->tetrimino->name[++i] != '.')
    write(1, &tetris->tetrimino->name[i], 1);
  write(1, " : ", 3);
  if (tetris->tetrimino->width == 0)
    write(1, "Error\n", 6);
  else
    {
      write(1, "Size ", 5);
      my_put_nbr(tetris->tetrimino->height);
      write(1, "*", 1);
      my_put_nbr(tetris->tetrimino->width);
      write(1, " : color ", 9);
      my_put_nbr(tetris->tetrimino->color);
      write(1, " :\n", 3);
      i = -1;
      while (++i < tetris->tetrimino->height)
	{
	  my_putstr(tetris->tetrimino->tetrimino[i]);
	  my_putchar('\n');
	}
    }
}

void	display_tetriminos(t_tetris *tetris)
{
  t_list_tetri	*elem_next;

  elem_next = tetris->list_tetri->next;
  while (elem_next != tetris->list_tetri)
    {
      print_tetriminos(elem_next);
      elem_next = elem_next->next;
    }
}

void	display_debug(t_tetris *tetris)
{
  write(1, "*** DEBUG MODE ***\n", 19);
  display_key(tetris);
  display_more_info(tetris);
  display_tetriminos(tetris);
  write(1, "Press a key to start Tetris\n", 28);
}
