/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Feb 27 23:39:59 2016 maud marel
** Last update Mon Feb 29 17:05:34 2016 maud marel
*/

#include <time.h>
#include "tetris.h"
#include <curses.h>

WINDOW		*create_newwin(int height, int width, int starty, int startx)
{
  WINDOW	*local_win;

  local_win = newwin(height, width, starty, startx);
  box(local_win, 0 , 0);
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

int		main(int ac, char **av)
{
  t_tetris	tetris;
  WINDOW	*score;
  WINDOW	*game;

  /* init_tetris(&tetris); */
  /* printf("%s\n", av[1]); */
  /* check_arg(&tetris, ac, av); */
  initscr();
  clear();
  refresh();
  tetris.start_time = time(0);
  score = create_newwin(15, 20, 5, 0);
  show_score(score, &tetris);
  game = create_newwin(22, 12, 0, 30);
  /* while (true) */
  /*   { */
  /*     tetris.time = time(0) - tetris.start_time; */
  /*     show_score(score, &tetris); */
  /*   } */
  getch();
  delwin(game);
  endwin();
  return (0);
}
