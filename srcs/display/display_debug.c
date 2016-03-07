/*
** display_debug.c for display_debug in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:25:57 2016 maud marel
** Last update Mon Mar  7 14:38:11 2016 maud marel
*/

#include <termios.h>
#include "tetris.h"

void	display_more_info(t_tetris *tetris)
{
  my_putstr("Next : ");
  if (tetris->options->hide_next == 0)
    my_putstr("Yes");
  else
    my_putstr("No");
  my_putchar('\n');
  my_putstr("Level : ");
  my_put_nbr(tetris->options->level);
  my_putchar('\n');
  my_putstr("Size : ");
  my_put_nbr(tetris->options->row - 2);
  my_putchar('*');
  my_put_nbr(tetris->options->col - 2);
  my_putchar('\n');
  my_putstr("Tetriminos : ");
  my_put_nbr(tetris->list_tetri->nb_tetri);
  my_putchar('\n');
}

void	print_tetriminos(t_list_tetri *tetris)
{
  int	i;

  i = -1;
  my_putstr("Tetriminos : Name ");
  while (tetris->tetrimino->name[++i] != '.')
    my_putchar(tetris->tetrimino->name[i]);
  my_putstr(" : ");
  if (tetris->tetrimino->width == 0)
    my_putstr("Error\n");
  else
    {
      my_putstr("Size ");
      my_put_nbr(tetris->tetrimino->width);
      my_putchar('*');
      my_put_nbr(tetris->tetrimino->height);
      my_putstr(" : Color ");
      my_put_nbr(tetris->tetrimino->color);
      my_putstr(" :\n");
      i = -1;
      while (++i < tetris->tetrimino->height)
	{
	  my_putstr(tetris->tetrimino->tetrimino[i]);
	  my_putchar('\n');
	}
    }
}

void		display_tetriminos(t_tetris *tetris)
{
  t_list_tetri	*elem_next;

  elem_next = tetris->list_tetri->next;
  while (elem_next != tetris->list_tetri)
    {
      print_tetriminos(elem_next);
      elem_next = elem_next->next;
    }
}

void			display_debug(t_tetris *tetris, int n)
{
  struct termios	term;

  if (n == 1)
    {
      my_putstr("*** DEBUG MODE ***\n");
      display_key(tetris);
      display_more_info(tetris);
      display_tetriminos(tetris);
      my_putstr("Press a key to start Tetris\n");
      if (tcgetattr(0, &term) == -1)
	exit(1);
      term.c_lflag &= ~(ICANON);
      term.c_lflag &= ~(ECHO);
      term.c_cc[VMIN] = 1;
      term.c_cc[VTIME] = 0;
      if (tcsetattr(0, TCSADRAIN, &term) == -1)
        exit(1);
      while (get_next_line(0) == NULL);
    }
}
