/*
** main_loop.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Mar  6 18:43:17 2016 Mathieu Sauvau
** Last update Tue Mar  8 15:14:30 2016 Mathieu Sauvau
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

void		loop(WINDOW *game, WINDOW *score, WINDOW *wnext,
		     t_tetris *tetris)
{
  int		r;
  float		i;
  t_tetri	*tetri;
  t_tetri	*next;
  int		nb_tetri;
  bool		move;
  char		buffer[10];
  bool		pause;

  i = 0;
  nb_tetri = max_tetri(tetris->list_tetri);
  tetri = random_tetri(tetris->list_tetri, nb_tetri);
  tetri->x = tetris->options->col / 2 - tetri->width / 2;
  tetri->y = -tetri->height;
  next = random_tetri(tetris->list_tetri, nb_tetri);
  if (tetris->options->hide_next == 0)
    show_next(wnext, next);
  mode_canon(0, 0, 0);
  pause = false;
  while (true)
    {
      if (!can_move_down(tetris, tetri))
	{
	  while (i < 20)
	    {
	      reset_buffer(buffer);
	      r = read(0, buffer, 10);
	      //      mvprintw(1, 0, "%d", r);
	      if (my_strcmp(buffer, tetris->options->left) == 0
		  && can_move_left(tetris, tetri) && !move)
		{
		  tetri->x -= 1;
		  move = true;
		}
	      if (my_strcmp(buffer, tetris->options->right) == 0
		  && can_move_right(tetris, tetri) && !move)
		{
		  tetri->x += 1;
		  move = true;
		}
	      print_game(game, tetris, tetri);
	      i += tetris->speed;
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
	{
	  //  mvprintw(0, 0, "%s", buffer);
	  if (my_strcmp(buffer, tetris->options->quit) == 0)
	    break;
	  if (my_strcmp(buffer, tetris->options->left) == 0
	      && can_move_left(tetris, tetri) && !move)
	    {
	      tetri->x -= 1;
	      move = true;
	    }
	  if (my_strcmp(buffer, tetris->options->right) == 0
	      && can_move_right(tetris, tetri) && !move)
	    {
	      tetri->x += 1;
	      move = true;
	    }
	  if (my_strcmp(buffer, tetris->options->turn) == 0)
	    rotate_tetri(tetri);
	  if (my_strcmp(buffer, tetris->options->drop) == 0  && !pause)
	    i += 5;
	  if (my_strcmp(buffer, tetris->options->pause) == 0)
	    pause = !pause;
	}
      if (!pause)
	i += tetris->speed;
      //      mvprintw(2, 0, "i =%f", i);
      //      refresh();
      if (i > 10)
	{
	  //	  mvprintw(2, 0, "i =%f", i);
	  if (can_move_down(tetris, tetri))
	    tetri->y += 1;
	  print_game(game, tetris, tetri);
	  move = false;
	  i = 0;
	}
      //      refresh();
      usleep(1);
    }
  mode_canon(1, 0, 0);
}
