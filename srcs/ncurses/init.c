/*
** init.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Mar  6 18:27:24 2016 Mathieu Sauvau
** Last update Mon Mar  7 20:16:34 2016 Mathieu Sauvau
*/

#include "tetris.h"

bool		check_window(t_tetris *tetris)
{
  int		x;
  int		y;

  getmaxyx(stdscr, y, x);
  if (x < tetris->options->col + 50 || y < tetris->options->row)
    {
      endwin();
      printf("Your terminal is too small to display the game please resize it\n");
      return (false);
    }
  return (true);
}

void	init_score(t_tetris *data)
{
  data->high_score = 0;
  data->score = 0;
  data->lines = 0;
  data->level = 0;
  data->speed = 0.001;
  data->time = 0;
}

void		check_color()
{
  if (has_colors())
    {
      start_color();
      init_pair(1, COLOR_RED, COLOR_RED);
      init_pair(2, COLOR_GREEN, COLOR_GREEN);
      init_pair(3, COLOR_BLUE, COLOR_BLUE);
      init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
      init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
      init_pair(6, COLOR_CYAN,COLOR_CYAN);
      init_pair(7, COLOR_WHITE, COLOR_WHITE);
    }
}

void		init_ncurses()
{
  initscr();
  curs_set(0);
  nodelay(stdscr, true);
  keypad(stdscr, true);
  noecho();
  clear();
  refresh();
  check_color();
}

char		**init_board(t_tetris *tetris)
{
  char		**board;
  int		x;
  int		y;

  y = -1;
  if ((board = malloc(sizeof(char *) * (tetris->options->row - 2))) == NULL)
    return (NULL);
  while (++y < tetris->options->row - 2)
    {
      x = -1;
      if ((board[y] = malloc(sizeof(char) * (tetris->options->col - 2))) == NULL)
	return (NULL);
      while (++x < tetris->options->col - 2)
	  board[y][x] = 0;
    }
  return (board);
}
