/*
** free_options.c for free_options in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_tetris/srcs/free
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Sun Mar  6 15:20:16 2016
** Last update Tue Mar  8 09:04:44 2016 maud marel
*/

#include "tetris.h"

void	free_options(t_tetris *tetris)
{
  free(tetris->options->left);
  free(tetris->options->right);
  free(tetris->options->turn);
  free(tetris->options->drop);
  free(tetris->options->quit);
  free(tetris->options->pause);
  free(tetris->options);
}
