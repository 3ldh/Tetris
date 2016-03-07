/*
** display_debug.c for display_debug in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:25:57 2016 maud marel
** Last update Mon Mar  7 12:59:17 2016 Mathieu Sauvau
*/

#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
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

void		mode_canon(int i, int time, int nb_char)
{
  static struct termios old;
  static struct termios new;

  if (i == 0)
    {
      ioctl(0, TCGETS, &old);
      ioctl(0, TCGETS, &new);
      new.c_lflag &= ~(ICANON);
      new.c_lflag &= ~(ECHO);
      new.c_cc[VMIN] = nb_char;
      new.c_cc[VTIME] = time;
      ioctl(0, TCSETS, &new);
    }
  if (i == 1)
    ioctl(0, TCSETS, &old);
}

void			display_debug(t_tetris *tetris, int n)
{
  char			buffer[10];
  if (n == 1)
    {
      my_putstr("*** DEBUG MODE ***\n");
      display_key(tetris);
      display_more_info(tetris);
      display_tetriminos(tetris);
      my_putstr("Press a key to start Tetris\n");
      mode_canon(0, 0, 1);
      read(0, buffer, 10);
      mode_canon(1, 0, 0);
    }
}
