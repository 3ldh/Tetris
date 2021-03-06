/*
** free_options.c for free_options in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_tetris/srcs/free
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Sun Mar  6 15:20:16 2016
** Last update Wed Mar  9 13:53:52 2016 Mathieu Sauvau
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
