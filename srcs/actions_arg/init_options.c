/*
** init_options.c for init_options in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 19:30:09 2016 maud marel
** Last update Mon Mar  7 13:25:06 2016 maud marel
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
  if ((tetris->options->left = malloc(sizeof(char) * 5)) == NULL
      || (tetris->options->right = malloc(sizeof(char) * 5)) == NULL
      || (tetris->options->turn = malloc(sizeof(char) * 5)) == NULL
      || (tetris->options->drop = malloc(sizeof(char) * 5)) == NULL
      || (tetris->options->quit = malloc(sizeof(char) * 2)) == NULL
      || (tetris->options->pause = malloc(sizeof(char) * 2)) == NULL)
    exit(1);
  my_strcpy(tetris->options->left, tigetstr("kcub1"));
  my_strcpy(tetris->options->right, tigetstr("kcuf1"));
  my_strcpy(tetris->options->turn, tigetstr("kcuu1"));
  my_strcpy(tetris->options->drop, tigetstr("kcud1"));
  my_strcpy(tetris->options->quit, "q");
  my_strcpy(tetris->options->pause, " ");
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
