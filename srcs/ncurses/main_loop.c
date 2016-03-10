/*
** main_loop.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Mar  6 18:43:17 2016 Mathieu Sauvau
** Last update Thu Mar 10 15:44:01 2016 Mathieu Sauvau
*/

#include <termios.h>
#include <sys/ioctl.h>
#include <time.h>
#include <unistd.h>
#include "tetris.h"

void		done(t_tetris *tetris,
		     t_tetri **tetri, t_tetri **next)
{
  if (!can_move_down(tetris, *tetri))
    {
      update_board(tetris, (*tetri));
      line_completion(tetris, tetris->wgame);
      show_board(tetris);
      //free_tetri(*tetri);
      *tetri = *next;
      (*tetri)->x = tetris->options->col / 2 - (*tetri)->width / 2;
      (*tetri)->y = -(*tetri)->height;
      *next = random_tetri(tetris->list_tetri, tetris->nb_tetri);
    }
}

void		do_(WINDOW *game, t_tetris *tetris, t_tetri *tetri)
{
  if (tetris->i > 8)
    {
      if (can_move_down(tetris, tetri))
	tetri->y += 1;
      print_game(game, tetris, tetri);
      tetris->moved = false;
      tetris->i = 0;
    }
  usleep(1);
}

void		last_call(WINDOW *game, t_tetris *tetris,
			  t_tetri *tetri)
{
  while (tetris->i < 20)
    {
      read_key(tetris, tetri);
      print_game(game, tetris, tetri);
    }
}

void		main_loop(t_tetris *tetris, t_tetri *tetri, t_tetri *next)
{
  while (true)
    {
      if (!can_move_down(tetris, tetri))
	{
	  last_call(tetris->wgame, tetris, tetri);
	  done(tetris, &tetri, &next);
	  if (tetris->options->hide_next == 0)
	    show_next(tetris->wnext, next);
	}
      tetris->time = time(0) - tetris->start_time;
      show_score(tetris->wscore, tetris);
      read_key(tetris, tetri);
      if (tetris->quit)
	break;
      do_(tetris->wgame, tetris, tetri);
    }
}

void		start_loop(t_tetris *tetris)
{
  t_tetri	*tetri;
  t_tetri	*next;

  tetri = init_first_loop(tetris);
  tetris->key_tab = get_fct_key(tetris);
  next = random_tetri(tetris->list_tetri, tetris->nb_tetri);
  if (tetris->options->hide_next == 0)
    show_next(tetris->wnext, next);
  main_loop(tetris, tetri, next);
}
