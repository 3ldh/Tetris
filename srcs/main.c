/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Feb 27 23:39:59 2016 maud marel
** Last update Sun Mar  6 18:47:05 2016 Mathieu Sauvau
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

void		show_tetri(t_list_tetri *elem)
{
  t_list_tetri	*elem_next;
  int		x;
  int		y;

  elem_next = elem->next;
  while (elem_next != elem)
    {
      printf("%s width = %d height = %d max = %d\n", elem_next->tetrimino->name
	     , elem_next->tetrimino->width, elem_next->tetrimino->height,
	     elem_next->tetrimino->max);
      y = -1;
      while (++y < elem_next->tetrimino->max)
      	{
      	  x = -1;
      	  while (++x < elem_next->tetrimino->max)
       	      printf("%c", elem_next->tetrimino->tetrimino[y][x]);
       	  printf("\n");
      	}
      printf("\n");
      elem_next = elem_next->next;
    }
}

int		main(int ac, char **av)
{
  t_tetris	tetris;
  WINDOW	*score;
  WINDOW	*game;
  WINDOW	*next;

  check_tetriminos(&tetris);
  init_tetris(&tetris);
  check_arg(&tetris, ac, av);
  srand(time(0));
  //  show_tetri(tetris.list_tetri);
  tetris.list_tetri = get_valid_tetri(tetris.list_tetri);
  center_tetri(tetris.list_tetri);
  /* show_tetri(tetris.list_tetri); */
  /* printf("name %s\n", tetris.list_tetri->next->next->next->tetrimino->name); */
  /* rotate_tetri(tetris.list_tetri->next->next->next->tetrimino); */
  /* rotate_tetri(tetris.list_tetri->next->next->next->tetrimino); */
  //  rotate_tetri(tetris.list_tetri->next->next->next->tetrimino);
  show_tetri(tetris.list_tetri);
  init_ncurses();
  if (!check_window(&tetris))
    return (1);
  init_score(&tetris);
  tetris.start_time = time(0);
  if ((score = create_newwin(15, 22, 5, 0)) == NULL
      || (next = create_newwin(7, 15, 0, tetris.options->col + 35)) == NULL)
    return (1);
  show_score(score, &tetris);
  if ((tetris.board = init_board(&tetris)) == NULL)
    return (1);
  show_board(&tetris);
  if ((game = create_newwin(tetris.options->row, tetris.options->col, 0, 30)) == NULL)
    return (1);
  loop(game, score, next, &tetris);
  getch();
  delwin(game);
  endwin();
  return (0);
}
