/*
** main_loop.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Mar  6 18:43:17 2016 Mathieu Sauvau
** Last update Sun Mar  6 18:44:44 2016 Mathieu Sauvau
*/

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

void		loop(WINDOW *game, WINDOW *score, WINDOW *wnext,
		     t_tetris *tetris)
{
  char		*c;
  float		i;
  t_list_tetri	*valid_tetri;
  t_tetri	*tetri;
  t_tetri	*next;
  int		nb_tetri;
  bool		move;

  i = 0;
  valid_tetri = tetris->list_tetri;
  nb_tetri = max_tetri(valid_tetri);
  tetri = random_tetri(valid_tetri, nb_tetri);
  tetri->x = tetris->options->col / 2;
  tetri->y = -tetri->height;
  next = random_tetri(valid_tetri, nb_tetri);
  show_next(wnext, next);
  while (true)
    {
      if (!can_move_down(tetris, tetri))
	{
	  while (i < 20)
	    {
	      c = getch();
	      if (c == KEY_RIGHT && can_move_right(tetris, tetri) && !move)
		{
		  tetri->x += 1;
		  move = true;
		}
	      else if (c == KEY_LEFT && can_move_left(tetris, tetri) && !move)
		{
		  tetri->x -= 1;
		  move = true;
		}
	      print_game(game, tetris, tetri);
	      i += tetris->speed;
	    }
	  if (!can_move_down(tetris, tetri))
	    {
	      update_board(game, tetris, tetri);
	      line_completion(tetris, game);
	      show_board(tetris);
	      tetri = next;
	      tetri->x = tetris->options->col / 2;
	      tetri->y = -tetri->height;
	      next = random_tetri(valid_tetri, nb_tetri);
	      show_next(wnext, next);
	    }
	}
      tetris->time = time(0) - tetris->start_time;
      show_score(score, tetris);
      c = getch();
      if (c == 'q')
	break;
      if (c == KEY_LEFT && can_move_left(tetris, tetri) && !move)
	{
	  tetri->x -= 1;
	  move = true;
	}
      if (c == KEY_RIGHT && can_move_right(tetris, tetri) && !move)
	{
	  tetri->x += 1;
	  move = true;
	}
      if (c == KEY_UP)
	rotate_tetri(tetri);
      if (c == KEY_DOWN)
	i += 5;
      else
	i += tetris->speed;
      if (i > 10)
	{
	  if (can_move_down(tetris, tetri))
	    tetri->y += 1;
	  print_game(game, tetris, tetri);
	  move = false;
	  i = 0;
	}
      usleep(1);
    }
}
