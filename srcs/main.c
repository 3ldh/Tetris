/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Feb 27 23:39:59 2016 maud marel
** Last update Fri Mar 18 23:38:45 2016 
*/

#include <time.h>
#include <stdlib.h>
#include "tetris.h"

bool		launch_all(t_tetris *tetris)
{
  if (!init_ncurses() && !check_window(tetris))
    return (false);
  init_score(tetris);
  tetris->start_time = time(0);
  if ((tetris->wscore = create_newwin(15, 22, 5, 0)) == NULL
      || (tetris->wnext = create_newwin(7, 15, 0, tetris->options->col + 35))
      == NULL)
    return (false);
  show_score(tetris->wscore, tetris);
  if ((tetris->board = init_board(tetris)) == NULL)
    return (false);
  if ((tetris->wgame
       = create_newwin(tetris->options->row, tetris->options->col, 0, 30))
      == NULL)
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
