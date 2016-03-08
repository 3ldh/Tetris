/*
** main_loop.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Mar  6 18:43:17 2016 Mathieu Sauvau
** Last update Tue Mar  8 17:20:52 2016 Mathieu Sauvau
*/

#include <termios.h>
#include <sys/ioctl.h>
#include <time.h>
#include <unistd.h>
#include "tetris.h"

t_tetri		*cpy_tetri(t_tetri *tetri)
{
  t_tetri	*new_tetri;
  int		x;
  int		y;

  if ((new_tetri = malloc(sizeof(t_tetri))) == NULL
      || (new_tetri->tetrimino = malloc(sizeof(char *) * tetri->max)) == NULL)
      return (NULL);
  new_tetri->max = tetri->max;
  new_tetri->height = tetri->height;
  new_tetri->width = tetri->width;
  new_tetri->color = tetri->color;
  new_tetri->x = tetri->x;
  new_tetri->y = tetri->y;
  y = -1;
  while (++y < new_tetri->max)
    {
      x = -1;
      if ((new_tetri->tetrimino[y] = malloc(sizeof(char) * tetri->max)) == NULL)
  	return (NULL);
      while (++x < new_tetri->max)
      	new_tetri->tetrimino[y][x] = tetri->tetrimino[y][x];
    }
  return (new_tetri);
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
  t_tetri	*result;
  int		r;
  int		n;

  elem = list_tetri->next;
  n = -1;
  r = rand() % nb_tetri;
  while (elem != list_tetri && ++n != r)
    elem = elem->next;
  result = cpy_tetri(elem->tetrimino);
  return (result);
}

void		reset_buffer(char *buffer)
{
  int		i;

  i = -1;
  while(++i < 10)
    buffer[i] = 0;
}

void			rotate(UNUSED t_tetris *data, t_tetri *tetri)
{
  rotate_tetri(tetri);
}

void			move_left(t_tetris *data, t_tetri *tetri)
{
  if (can_move_left(data, tetri) && !data->moved)
    {
      tetri->x -= 1;
      data->moved = true;
    }
}

void			move_right(t_tetris *data, t_tetri *tetri)
{
  if (can_move_right(data, tetri) && !data->moved)
    {
      tetri->x += 1;
      data->moved = true;
    }
}

void			drop(t_tetris *data, UNUSED t_tetri *tetri)
{
  if (!data->pause)
    data->i += 5;
}

void			quit(t_tetris *data, UNUSED t_tetri *tetri)
{
  data->quit = true;
}

void			do_pause(t_tetris *data, UNUSED t_tetri *tetri)
{
  data->pause = !data->pause;
}

t_key_fct		*get_fct_key(t_tetris *tetris)
{
  t_key_fct		*tab;

  if ((tab = malloc(sizeof(t_check_opt_simp) * MAX_CHECK_OPT_SIMP)) == NULL)
    exit(1);
  tab[LEFT_S].key = tetris->options->left;
  tab[LEFT_S].ft_simp = &move_left;
  tab[RIGHT_S].key = tetris->options->right;
  tab[RIGHT_S].ft_simp = &move_right;
  tab[TURN_S].key = tetris->options->turn;
  tab[TURN_S].ft_simp = &rotate;
  tab[DROP_S].key = tetris->options->drop;
  tab[DROP_S].ft_simp = &drop;
  tab[QUIT_S].key = tetris->options->quit;
  tab[QUIT_S].ft_simp = &quit;
  tab[PAUSE_S].key = tetris->options->pause;
  tab[PAUSE_S].ft_simp = &do_pause;
  return (tab);
}

int			key(t_key_fct *key_tab, t_tetris *tetris,
			    char *buffer, t_tetri *tetri)
{
  int			i;

  i = 0;
  while (++i < MAX_CHECK_OPT_SIMP)
    {
      if (my_strcmp(buffer, key_tab[i].key) == 0)
	{
	  key_tab[i].ft_simp(tetris, tetri);
	  return (0);
	}
    }
  return (1);
}

void		loop(WINDOW *game, WINDOW *score, WINDOW *wnext,
		     t_tetris *tetris)
{
  int		r;
  t_tetri	*tetri;
  t_tetri	*next;
  int		nb_tetri;
  bool		move;
  char		buffer[10];
  t_key_fct	*key_tab;

  key_tab = get_fct_key(tetris);
  nb_tetri = max_tetri(tetris->list_tetri);
  tetri = random_tetri(tetris->list_tetri, nb_tetri);
  tetri->x = tetris->options->col / 2 - tetri->width / 2;
  tetri->y = -tetri->height;
  next = random_tetri(tetris->list_tetri, nb_tetri);
  if (tetris->options->hide_next == 0)
    show_next(wnext, next);
  mode_canon(0, 0, 0);
  while (true)
    {
      if (!can_move_down(tetris, tetri))
	{
	  while (tetris->i < 16)
	    {
	      reset_buffer(buffer);
	      r = read(0, buffer, 10);
	      key(key_tab, tetris, buffer, tetri);
	      print_game(game, tetris, tetri);
	      tetris->i += tetris->speed;
	    }
	  if (!can_move_down(tetris, tetri))
	    {
	      update_board(tetris, tetri);
	      line_completion(tetris, game);
	      show_board(tetris);
	      tetri = next;
	      tetri->x = tetris->options->col / 2 - tetri->width / 2;
	      tetri->y = -tetri->height;
	      next = random_tetri(tetris->list_tetri, nb_tetri);
	      if (tetris->options->hide_next == 0)
		show_next(wnext, next);
	    }
	}
      tetris->time = time(0) - tetris->start_time;
      show_score(score, tetris);
      reset_buffer(buffer);
      r = read(0, buffer, 10);
      //      mvprintw(1, 0, "%d", r);
      if (r > 0)
	key(key_tab, tetris, buffer, tetri);
      if (tetris->quit)
	break;
      if (!tetris->pause)
	tetris->i += tetris->speed;
      //      mvprintw(2, 0, "i =%f", i);
      //      refresh();
      if (tetris->i > 8)
	{
	  //	  mvprintw(2, 0, "i =%f", i);
	  if (can_move_down(tetris, tetri))
	    tetri->y += 1;
	  print_game(game, tetris, tetri);
	  tetris->moved = false;
	  tetris->i = 0;
	}
      //      refresh();
      usleep(1);
    }
  mode_canon(1, 0, 0);
}
