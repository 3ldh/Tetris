/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Feb 27 23:39:59 2016 maud marel
** Last update Mon Mar 14 19:36:06 2016 Mathieu Sauvau
*/

#include <time.h>
#include <stdlib.h>
#include "tetris.h"

WINDOW		*create_newwin(int height, int width, int starty, int startx)
{
  WINDOW	*local_win;

  local_win = newwin(height, width, starty, startx);
  wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');
  wrefresh(local_win);
  return (local_win);
}

void		show_board(t_tetris *tetris)
{
  int		x;
  int		y;

  y = -1;
  while (++y < tetris->options->row - 2)
    {
      x = -1;
      while (++x < tetris->options->col - 2)
	mvprintw(y, x + 60,"%d", tetris->board[y][x]);
      printw("\n");
    }
}

void		show_tetri(t_tetri *tetri)
{
  int		x;
  int		y;

  y = -1;
  while (++y < tetri->max)
    {
      x = -1;
      while (++x < tetri->max);
    }
}

void		show_list_tetri(t_list_tetri *elem)
{
  t_list_tetri	*elem_next;

  elem_next = elem->next;
  while (elem_next != elem)
    {
      show_tetri(elem_next->tetrimino);
      elem_next = elem_next->next;
    }
}

void		show_logo(WINDOW *win)
{
  mvwprintw(win, 0, 0, "***  ** *** *** * ***\n");
  mvwprintw(win, 1, 0, " *   *   *  * *   *  \n");
  mvwprintw(win, 2, 0, " *   **  *   ** * ***\n");
  mvwprintw(win, 3, 0, " *   *   *  * * *   *\n");
  mvwprintw(win, 4, 0, " *   **  *  * * * ***\n");
  wrefresh(win);
}

bool		launch_all(t_tetris *tetris)
{
  if (!init_ncurses() && !check_window(tetris))
    return (false);
  init_score(tetris);
  tetris->start_time = time(0);
  if ((tetris->wscore = create_newwin(15, 22, 5, 0)) == NULL
      || (tetris->wnext = create_newwin(7, 15, 0, tetris->options->col + 35)) == NULL)
    return (false);
  show_score(tetris->wscore, tetris);
  if ((tetris->board = init_board(tetris)) == NULL)
    return (false);
  if ((tetris->wgame
       = create_newwin(tetris->options->row, tetris->options->col, 0, 30)) == NULL)
    return (false);
  start_loop(tetris);
  mode_canon(1, 0, 0);
  return (true);
}

int		main(int ac, char **av, char **env)
{
  t_tetris	tetris;

  if (env == NULL)
    return (-1);
  if (check_tetriminos(&tetris) == -1)
    return (-1);
  init_tetris(&tetris);
  if (read_arg(&tetris, ac, av) == -1)
    return (-1);
  verif_size_all(&tetris);
  srand(time(0));
  tetris.list_tetri = get_valid_tetri(tetris.list_tetri);
  if (!launch_all(&tetris))
    return (1);
  endwin();
  free_struct(&tetris);
  return (0);
}
