/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Feb 27 23:39:59 2016 maud marel
** Last update Wed Mar  2 10:29:07 2016 Mathieu Sauvau
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
  tetri->x = 5;
  tetri->y = 2;
  tetri->name = "barre";
  tetri->tetrimino = malloc(sizeof(char *) * tetri->width);
  int i = -1;
  while (++i < 4)
    {
      tetri->tetrimino[i] = malloc(sizeof(char) * tetri->height);
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

void	print_game(WINDOW *game, t_tetri *tetri, t_list_tetri *static_tetri)
{
  werase(game);
  wborder(game, '|', '|', '-', '-', '+', '+', '+', '+');
  wrefresh(game);
  print_tetri(game, tetri);
  while (static_tetri != NULL)
    {
      print_tetri(game, &static_tetri->tetrimino);
      static_tetri = static_tetri->next;
    }
}

bool		space_occupied(t_tetris *data, t_tetri *tetri,
			      t_list_tetri *static_tetri)
{
  int		x;
  int		y;
  int		x2;
  int		y2;

  while (static_tetri != NULL)
    {
      x = -1;
      while (++x < tetri->width)
	{
	  y = -1;
	  while (++y < tetri->height)
	    if (tetri->y > 0)
	      if (data->tab_pos[y + tetri->y][x + tetri->x - 1] == 1)
		return (true);
	}
      static_tetri = static_tetri->next;
    }
  return (false);
}

bool		can_move_left(t_tetris *data, t_tetri *tetri,
			      t_list_tetri *static_tetri)
{
  if (tetri->x - 1 <= 0
      || space_occupied(data, tetri, static_tetri))
    return (false);
  return (true);
}

bool		can_move_right(t_tetris *data, t_tetri *tetri,
			      t_list_tetri *static_tetri)
{
  if (tetri->x + tetri->width + 1 >= data->options->col
      || space_occupied(data, tetri, static_tetri))
    return (false);
  return (true);
}

t_list_tetri	*add_tetri(t_list_tetri *list, t_tetri *tetri)
{
  t_list_tetri	*new;

  if ((new = malloc(sizeof(t_list_tetri))) == NULL)
    exit(1);
  new->tetrimino = *tetri;
  new->prev = NULL;
  new->next = list;
  return (new);
}

/* void		print_list(t_list_tetri *list) */
/* { */
/*   int		x; */
/*   int		y; */

/*   while (list != NULL) */
/*     { */
/*       x = -1; */
/*       while (++x < list->tetrimino.width) */
/* 	{ */
/* 	  y = -1; */
/* 	  while (++y < list->tetrimino.height) */
/* 	    printf("%c\n", list->tetrimino.tetrimino[x][y]); */
/* 	} */
/*       list = list->next; */
/*       printf("\n"); */
/*     } */
/* } */

/* void test() */
/* { */
/*   t_list_tetri	*static_tetri; */
/*   t_tetri	tetri; */

/*   init_tetri(&tetri); */
/*   static_tetri = NULL; */
/*   add_tetri(static_tetri, &tetri); */
/*   static_tetri = add_tetri(static_tetri, &tetri); */
/*   print_list(static_tetri); */
/* } */

void		show_tab_pos(t_tetris *tetris)
{
  int		x;
  int		y;

  y = -1;
  while (++y < tetris->options->row - 2)
    {
      x = -1;
      while (++x < tetris->options->col - 2)
	mvprintw(y, x + 60,"%d", tetris->tab_pos[y][x]);
      printw("\n");
    }
}

bool		can_move_down(t_tetris *data, t_tetri *tetri,
			      t_list_tetri *static_tetri)
{
  if (tetri->y + tetri->height + 1 >= data->options->row
      || space_occupied(data, tetri, static_tetri))
    return (false);
  return (true);
}

void		show_next(WINDOW *wnext, t_tetris *tetris,
			  t_tetri *next, t_tetri *cur)
{
  //  cur = next;
  cur->x = tetris->options->col / 2;
  cur->y = -cur->height;
  init_tetri(next);
  mvwprintw(wnext, 0, 1, "Next");
  print_tetri(wnext, next);
  wrefresh(wnext);
}

void		update_tab_pos(t_tetris *tetris, t_tetri *tetri)
{
  int		x;
  int		y;
  int		pos_x;
  int		pos_y;

  x = -1;
  while(++x < tetri->width)
    {
      y = -1;
      while(++y < tetri->height)
	{
	  if (tetri->tetrimino[x][y] == '*')
	    {
	      pos_x = x + tetri->x;
	      pos_y = y + tetri->y;
	      tetris->tab_pos[pos_y - 1][pos_x - 1] = 1;
	    }
	}
    }
}

void		loop(WINDOW *game, WINDOW *score, WINDOW *wnext,
		     t_tetris *tetris)
{
  char		*c;
  float		i;
  t_list_tetri	*static_tetri;
  t_tetri	tetri;
  t_tetri	next;

  i = 0;
  init_tetri(&tetri);
  tetris->speed = 10;
  show_next(wnext, tetris, &next, &tetri);
  static_tetri = NULL;
  while (true)
    {
      if (!can_move_down(tetris, &tetri, static_tetri))
	{
	  static_tetri = add_tetri(static_tetri, &tetri);
	  update_tab_pos(tetris, &tetri);
	  show_tab_pos(tetris);
	  show_next(wnext, tetris, &next, &tetri);
	}
      tetris->time = time(0) - tetris->start_time;
      show_score(score, tetris);
      c = getch();
      if (c == 'q')
	break;
      if (c == KEY_LEFT && can_move_left(tetris, &tetri, static_tetri))
	tetri.x -= 1;
      if (c == KEY_RIGHT && can_move_right(tetris, &tetri, static_tetri))
	tetri.x += 1;
      if (c == KEY_DOWN)
	i += 5;
      else
	i += 0.001;
      if (i > tetris->speed)
	{
	  if (can_move_down(tetris, &tetri, static_tetri))
	    {
	      tetri.y += 1;
	    }
	  print_game(game, &tetri, static_tetri);
	  i = 0;
	}
      usleep(1);
    }
}

void		init_ncurses()
{
<<<<<<< HEAD
  initscr();
  curs_set(0);
  nodelay(stdscr, true);
  keypad(stdscr, true);
  noecho();
  clear();
  refresh();
  check_color();
}

char		**init_tab_pos(t_tetris *tetris)
{
  char		**tab_pos;
  int		x;
  int		y;

  y = -1;
  if ((tab_pos = malloc(sizeof(char *) * (tetris->options->row - 2))) == NULL)
    return (NULL);
  while (++y < tetris->options->row - 2)
    {
      x = -1;
      if ((tab_pos[y] = malloc(sizeof(char) * (tetris->options->col - 2))) == NULL)
	return (NULL);
      while (++x < tetris->options->col - 2)
	  tab_pos[y][x] = 0;
    }
  return (tab_pos);
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
  init_tetris(&tetris);
  check_arg(&tetris, ac, av);
  init_ncurses();
  tetris.start_time = time(0);
  score = create_newwin(15, 22, 5, 0);
  next = create_newwin(7, 15, 0, tetris.options->col + 35);
  show_score(score, &tetris);
  tetris.tab_pos = init_tab_pos(&tetris);
  show_tab_pos(&tetris);
  game = create_newwin(tetris.options->row, tetris.options->col, 0, 30);
  loop(game, score, next, &tetris);
  getch();
  delwin(game);
  endwin();
  return (0);
}
