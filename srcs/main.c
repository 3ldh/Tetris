/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Feb 27 23:39:59 2016 maud marel
** Last update Mon Feb 29 19:43:48 2016 Mathieu Sauvau
*/

#include <time.h>
#include <stdlib.h>
#include "tetris.h"
#include <curses.h>

WINDOW		*create_newwin(int height, int width, int starty, int startx)
{
  WINDOW	*local_win;

  local_win = newwin(height, width, starty, startx);
  wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');
  wrefresh(local_win);
  return (local_win);
}

void		show_score(WINDOW *wscore, t_tetris *tetris)
{
  mvwprintw(wscore, 1, 1, "High Score");
  mvwprintw(wscore, 1, 15, "%d\n", 1234567);
  mvwprintw(wscore, 2, 1, "Score");
  mvwprintw(wscore, 2, 15, "%d\n", tetris->score);
  mvwprintw(wscore, 4, 1, "Lines");
  mvwprintw(wscore, 4, 15, "%d\n", tetris->lines);
  mvwprintw(wscore, 5, 1, "Level");
  mvwprintw(wscore, 5, 15, "%d\n", tetris->level);
  mvwprintw(wscore, 7, 1, "Timer");
  mvwprintw(wscore, 7, 15, "%d:", tetris->time / 60);
  mvwprintw(wscore, 7, 17, "%d\n", tetris->time % 60);
  box(wscore, 0 , 0);
  wrefresh(wscore);
}

void		init_tetri(t_tetri *tetri)
{
  tetri->color = 6;
  tetri->height = 4;
  tetri->width = 1;
  tetri->name = "barre";
  tetri->tetrimino = malloc(sizeof(char *) * 4);
  int i = -1;
  while (++i < 4)
    {
      tetri->tetrimino[i] = malloc(sizeof(char));
      tetri->tetrimino[0][i] = '*';
    }
}

void		print_tetri(WINDOW *game, t_tetri *tetri)
{
  int		x;
  int		y;

  x = -1;
  wattron(game, COLOR_PAIR(tetri->color));
  while (++x < tetri->width)
    {
      y = -1;
      while (++y < tetri->height)
	mvwprintw(game, tetri->y + y, tetri->x + x, "%c", tetri->tetrimino[x][y]);
    }
  wrefresh(game);
  wattroff(game, COLOR_PAIR(tetri->color));
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
      init_pair(6, COLOR_CYAN, COLOR_CYAN);
      init_pair(7, COLOR_WHITE, COLOR_WHITE);
    }
}

void		do_game(WINDOW *game, t_tetri *tetri)
{
  ++tetri->y;
  werase(game);
  wborder(game, '|', '|', '-', '-', '+', '+', '+', '+');
  wrefresh(game);
  print_tetri(game, tetri);
}

void		loop(WINDOW *game, WINDOW *score, t_tetris *tetris)
{
  char		*c;
  float		i;
  t_tetri	tetri;

  i = 0;
  init_tetri(&tetri);
  tetris->speed = 30;
  tetri.x = 5;
  tetri.y = 0;
  while (true)
    {
      tetris->time = time(0) - tetris->start_time;
      show_score(score, tetris);
      c = getch();
      if (c == KEY_LEFT)
	tetri.x -= 1;
      if (c == KEY_DOWN)
	  i += 5;
      else
	i += 0.001;
      if (i > tetris->speed)
	{
	  do_game(game, &tetri);
	  i = 0;
	}
      //usleep(1);
    }
}

int		main(int ac, char **av)
{
  t_tetris	tetris;
  WINDOW	*score;
  WINDOW	*game;
  WINDOW	*next;

  /* init_tetris(&tetris); */
  /* printf("%s\n", av[1]); */
  /* check_arg(&tetris, ac, av); */
  initscr();
  curs_set(0);
  keypad(stdscr, true);
  noecho();
  clear();
  refresh();
  check_color();
  tetris.start_time = time(0);
  score = create_newwin(15, 20, 5, 0);
  show_score(score, &tetris);
  //recupere les row et col de la sructure option
  game = create_newwin(22, 12, 0, 30);
  nodelay(stdscr, true);
  loop(game, score, &tetris);
  getch();
  delwin(game);
  endwin();
  return (0);
}
