/*
** init_options.c for init_options in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 19:30:09 2016 maud marel
** Last update Tue Mar  8 09:36:26 2016 maud marel
*/

#include "tetris.h"
#include <curses.h>
#include <term.h>

void	init_direct(t_tetris *tetris)
{
  int	i;
  int	ret;

  i = setupterm(NULL, 0, &ret);
  if (i == ERR)
    display_help_error();
  tetris->options->left = my_strdup(tigetstr("kcub1"));
  tetris->options->right = my_strdup(tigetstr("kcuf1"));
  tetris->options->turn = my_strdup(tigetstr("kcuu1"));
  tetris->options->drop = my_strdup(tigetstr("kcud1"));
  tetris->options->quit = my_strdup("q");
  tetris->options->pause = my_strdup(" ");
}

void	init_tetris(t_tetris *tetris)
{

  if ((tetris->options = malloc(sizeof(t_options))) == NULL)
    exit(1);
  tetris->options->level = 1;
  tetris->options->row = 22;
  tetris->options->col = 12;
  tetris->options->hide_next = 0;
  init_direct(tetris);
}
