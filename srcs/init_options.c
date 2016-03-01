/*
** init_options.c for init_options in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 19:30:09 2016 maud marel
** Last update Tue Mar  1 22:17:16 2016 maud marel
*/

#include "tetris.h"

void	init_tetris(t_tetris *tetris)
{
  if ((tetris->options = malloc(sizeof(t_options))) == NULL)
    exit(1);
  tetris->options->level = 1;
  tetris->options->row = 20;
  tetris->options->col = 10;
  tetris->options->hide_next = 0;
  tetris->options->left = 'l';
  tetris->options->right = 'r';
  tetris->options->turn = 't';
  tetris->options->drop = 'd';
  tetris->options->quit = 'q';
  tetris->options->pause = 'p';
}
