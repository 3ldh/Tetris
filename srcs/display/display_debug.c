/*
** display_debug.c for display_debug in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:25:57 2016 maud marel
** Last update Sat Mar  5 15:54:04 2016 maud marel
*/

#include <termios.h>
#include "tetris.h"

void	display_key(t_tetris *tetris)
{
  my_putstr("Key Left : ");
  my_putstr(tetris->options->left);
  my_putchar('\n');
  my_putstr("Key Right : ");
  my_putstr(tetris->options->right);
  my_putchar('\n');
  my_putstr("Key Turn : ");
  my_putstr(tetris->options->turn);
  my_putchar('\n');
  my_putstr("Key Drop : ");
  my_putstr(tetris->options->drop);
  my_putchar('\n');
  my_putstr("Key Quit : ");
  my_putstr(tetris->options->quit);
  my_putchar('\n');
  my_putstr("Key Pause : ");
  my_putstr(tetris->options->pause);
  my_putchar('\n');
}

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
      my_put_nbr(tetris->tetrimino->height);
      my_putchar('*');
      my_put_nbr(tetris->tetrimino->width);
      my_putstr(" : color ");
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
  char			*name_term;
  struct termios	term;

  if (n == 1)
    {
      my_putstr("*** DEBUG MODE ***\n");
      display_key(tetris);
      display_more_info(tetris);
      display_tetriminos(tetris);
      my_putstr("Press a key to start Tetris\n");
      if ((name_term = getenv("TERM")) == NULL)
	exit(1);
      if (tgetent(NULL, name_term) == ERR)
	exit(1);
      if (tcgetattr(0, &term) == -1)
	exit(1);
      term.c_lflag &= ~(ICANON);
      term.c_lflag &= ~(ECHO);
      term.c_cc[VMIN] = 0;
      term.c_cc[VTIME] = 0;
      if (tcsetattr(0, TCSADRAIN, &term) == -1)
        exit(1);
      while (get_next_line(0) == NULL);
    }
}
