/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Feb 27 23:39:59 2016 maud marel
** Last update Sun Mar  6 16:28:08 2016 
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

void		show_score(WINDOW *wscore, t_tetris *tetris)
{
  mvwprintw(wscore, 1, 1, "High Score");
  mvwprintw(wscore, 1, 15, "%d\n", tetris->high_score);
  mvwprintw(wscore, 2, 1, "Score");
  mvwprintw(wscore, 2, 15, "%d\n", tetris->score);
  mvwprintw(wscore, 4, 1, "Lines");
  mvwprintw(wscore, 4, 15, "%d\n", tetris->lines);
  mvwprintw(wscore, 5, 1, "Level");
  mvwprintw(wscore, 5, 15, "%d\n", tetris->level);
  mvwprintw(wscore, 7, 1, "Timer");
  mvwprintw(wscore, 7, 15, "%d:", tetris->time / 60);
  mvwprintw(wscore, 7, 17, "%.2d\n", tetris->time % 60);
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

  y = -1;
  wattron(game, COLOR_PAIR(tetri->color));
  while (++y < tetri->height)
    {
      x = -1;
      while (++x < tetri->width)
	if (tetri->tetrimino[y][x] == '*')
	  mvwprintw(game, tetri->y + y, tetri->x + x, "%c", tetri->tetrimino[y][x]);
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
      init_pair(6, COLOR_CYAN,COLOR_CYAN);
      init_pair(7, COLOR_WHITE, COLOR_WHITE);
    }
}

void	print_game(WINDOW *game, t_tetris *data, t_tetri *tetri)
{
  int	x;
  int	y;

  werase(game);
  y = -1;
  while (++y < data->options->row - 2)
    {
      x = -1;
      while (++x < data->options->col - 2)
  	{
  	    if (data->board[y][x] != 0)
  	      {
  		wattron(game, COLOR_PAIR(data->board[y][x]));
  		mvwprintw(game, y + 1, x + 1, "*\n");
  		wattroff(game, COLOR_PAIR(data->board[y][x]));
  	      }
  	}
    }
  wborder(game, '|', '|', '-', '-', '+', '+', '+', '+');
  print_tetri(game, tetri);
}

bool		space_occupied_down(t_tetris *data, t_tetri *tetri)
{
  int		x;
  int		y;

  y = -1;
  while (++y < tetri->height)
    {
      x = -1;
      while (++x < tetri->width)
	if (tetri->y > 0 && tetri->tetrimino[y][x] == '*'
	    && data->board[y + tetri->y][x + tetri->x - 1] != 0)
	  return (true);
    }
  return (false);
}

bool		space_occupied_right(t_tetris *data, t_tetri *tetri)
{
  int		x;
  int		y;

  y = -1;
  while (++y < tetri->height)
    {
      x = -1;
      while (++x < tetri->width)
	if (tetri->y > 0 && tetri->tetrimino[y][x] == '*'
	    && data->board[y + tetri->y - 1][x + tetri->x] != 0)
	  return (true);
    }
  return (false);
}

bool		space_occupied_left(t_tetris *data, t_tetri *tetri)
{
  int		x;
  int		y;

  y = -1;
  while (++y < tetri->height)
    {
      x = -1;
      while (++x < tetri->width)
	if (tetri->y > 0 && tetri->tetrimino[y][x] == '*'
	    && data->board[y + tetri->y - 1][x + tetri->x - 2] != 0)
	  return (true);
    }
  return (false);
}

bool		can_move_left(t_tetris *data, t_tetri *tetri)
{
  if (tetri->x - 1 <= 0
      || space_occupied_left(data, tetri))
    return (false);
  return (true);
}

bool		can_move_right(t_tetris *data, t_tetri *tetri)
{
  if (tetri->x + tetri->width + 1 >= data->options->col
      || space_occupied_right(data, tetri))
    return (false);
  return (true);
}

t_list_tetri	*add_tetri(t_list_tetri *list, t_tetri *tetri)
{
  t_list_tetri	*new;

  if ((new = malloc(sizeof(t_list_tetri))) == NULL
      || (new->tetrimino = malloc(sizeof(t_tetri))) == NULL)
    exit(1);
  *new->tetrimino = *tetri;
  new->prev = NULL;
  new->next = list;
  return (new);
}

int		max_tetri(t_list_tetri *list_tetri)
{
  t_list_tetri	*elem;
  int		n;

  elem = list_tetri->next;
  n = 0;
  while (elem != list_tetri)
    {
      ++n;
      elem = elem->next;
    }
  return (n);
}

t_tetri		*random_tetri(t_list_tetri *list_tetri, int nb_tetri)
{
  t_list_tetri	*elem;
  int		r;
  int		n;

  elem = list_tetri->next;
  n = -1;
  r = rand() % nb_tetri;
  while (elem != list_tetri && ++n != r)
    elem = elem->next;
  return (elem->tetrimino);
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

bool		can_move_down(t_tetris *data, t_tetri *tetri)
{
  if (tetri->y + tetri->height + 1 >= data->options->row
      || space_occupied_down(data, tetri))
    return (false);
  return (true);
}

void		show_next(WINDOW *wnext,t_tetri *next)
{
  werase(wnext);
  wborder(wnext, '|', '|', '-', '-', '+', '+', '+', '+');
  mvwprintw(wnext, 0, 1, "Next");
  next->x = 5;
  next->y = 2;
  print_tetri(wnext, next);
  wrefresh(wnext);
}

void		update_board(WINDOW *game, t_tetris *tetris, t_tetri *tetri)
{
  int		x;
  int		y;
  int		pos_x;
  int		pos_y;

  y = -1;
  while (++y < tetri->height)
    {
      x = -1;
      while (++x < tetri->width)
	{
	  if (tetri->tetrimino[y][x] == '*')
	    {
	      pos_x = x + tetri->x - 1;
	      pos_y = y + tetri->y - 1;
	      tetris->board[pos_y][pos_x] = tetri->color;
	    }
	}
    }
}

void		clear_line(t_tetris *data, int line)
{
  int		x;

  x = -1;
  while (++x < data->options->col - 2)
    data->board[line][x] = 0;
}

void		fall(WINDOW *game, t_tetris *data)
{
  int		x;
  int		y;
  int		i;

  y = data->options->row - 2;
  while (--y >= 0)
    {
      x = data->options->col - 2;
      while (--x >= 0)
	{
	  if (y - 1 > 0
	      && data->board[y][x] == 0)
	    {
	      data->board[y][x] = data->board[y - 1][x];
	      data->board[y - 1][x] = 0;
	    }
	}
      usleep(100);
      wrefresh(game);
    }
}

void		line_completion(t_tetris *data, WINDOW *game)
{
  int		x;
  int		y;
  bool		is_complete;

  y = -1;
  while (++y < data->options->row - 2)
    {
      x = -1;
      is_complete = true;
      while (++x < data->options->col - 2)
	{
	  if (data->board[y][x] == 0)
	    {
	      is_complete = false;
	      break;
	    }
	}
      if (is_complete)
	{
	  ++data->lines;
	  clear_line(data, y);
	  fall(game, data);
	}
    }
}

t_list_tetri	*get_valid_tetri(t_list_tetri *all_tetri)
{
  t_list_tetri	*valid;
  int		n;

  valid = all_tetri->next;
  while (valid != all_tetri)
    {
      if (valid->tetrimino->width == 0)
	{
	  valid->prev->next = valid->next;
	  valid->next->prev = valid->prev;
	}
      valid = valid->next;
    }
  return (valid);
}

void		loop(WINDOW *game, WINDOW *score, WINDOW *wnext,
		     t_tetris *tetris)
{
  char		*c;
  float		i;
  t_list_tetri	*valid_tetri;
  t_tetri	tetri;
  t_tetri	next;
  int		nb_tetri;
  bool		move;

  i = 0;
  valid_tetri = get_valid_tetri(tetris->list_tetri);
  nb_tetri = max_tetri(valid_tetri);
  tetri = *random_tetri(valid_tetri, nb_tetri);
  tetri.x = tetris->options->col / 2;
  tetri.y = -tetri.height;
  next = *random_tetri(valid_tetri, nb_tetri);
  show_next(wnext, &next);
  while (true)
    {
      if (!can_move_down(tetris, &tetri))
	{
	  while (i < tetris->speed + 5)
	    {
	      c = getch();
	      if (c == KEY_RIGHT && can_move_right(tetris, &tetri) && !move)
		{
		  tetri.x += 1;
		  move = true;
		}
	      else if (c == KEY_LEFT && can_move_left(tetris, &tetri) && !move)
		{
		  tetri.x -= 1;
		  move = true;
		}
	      print_game(game, tetris, &tetri);
	      i += 0.001;
	    }
	  if (!can_move_down(tetris, & tetri))
	    {
	      update_board(game, tetris, &tetri);
	      line_completion(tetris, game);
	      show_board(tetris);
	      tetri = next;
	      tetri.x = tetris->options->col / 2;
	      tetri.y = -tetri.height;
	      next = *random_tetri(valid_tetri, nb_tetri);
	      show_next(wnext, &next);
	    }
	}
      tetris->time = time(0) - tetris->start_time;
      show_score(score, tetris);
      c = getch();
      if (c == 'q')
	break;
      if (c == KEY_LEFT && can_move_left(tetris, &tetri) && !move)
	{
	  tetri.x -= 1;
	  move = true;
	}
      if (c == KEY_RIGHT && can_move_right(tetris, &tetri) && !move)
	{
	  tetri.x += 1;
	  move = true;
	}
      if (c == KEY_DOWN)
	i += 5;
      else
	i += 0.001;
      if (i > tetris->speed)
	{
	  if (can_move_down(tetris, &tetri))
	    tetri.y += 1;
	  print_game(game, tetris, &tetri);
	  move = false;
	  i = 0;
	}
      usleep(1);
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

t_tetri		*rotate_tetri(t_tetri *tetri)
{
  return (tetri);
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

void		show_tetri(t_list_tetri *elem)
{
  t_list_tetri	*elem_next;
  int		x;
  int		y;

  elem_next = elem->next;
  while (elem_next != elem)
    {
      printf("%s\n", elem_next->tetrimino->name);
      printf("%d\n", elem_next->tetrimino->width);
      printf("%d\n", elem_next->tetrimino->height);
      y = -1;
      while (++y < elem_next->tetrimino->height)
      	{
      	  x = -1;
      	  while (++x < elem_next->tetrimino->width)
      	    {
      	      printf("%c", elem_next->tetrimino->tetrimino[y][x]);
      	    }
      	  printf("\n");
      	}
      printf("\n");
      elem_next = elem_next->next;
    }
}

void	init_score(t_tetris *data)
{
  data->high_score = 0;
  data->score = 0;
  data->lines = 0;
  data->level = 0;
  data->speed = 10;
}

int		main(int ac, char **av, char **env)
{
  t_tetris	tetris;
  WINDOW	*score;
  WINDOW	*game;
  WINDOW	*next;

  if (env == NULL)
    return (-1);
  check_tetriminos(&tetris);
  init_tetris(&tetris);
  read_arg(&tetris, ac, av);
  verif_size_all(&tetris);
  srand(time(0));
  /* show_tetri(tetris.list_tetri); */
  init_ncurses();
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
  free_options(&tetris);
  free_struct(&tetris);
  return (0);
}
