/*
** init_options.c for init_options in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 19:30:09 2016 maud marel
** Last update Sun Feb 28 23:15:28 2016 maud marel
*/

#include "tetris.h"

void	init_tetris(t_tetris *tetris)
{
  tetris->options->level = 1;
  my_strcpy(tetris->options->row, "20");
  my_strcpy(tetris->options->col, "10");
  tetris->options->hide_next = 0;
  my_strcpy(tetris->options->left, "^E[C");
  my_strcpy(tetris->options->right, "^E[D");
  my_strcpy(tetris->options->turn, "");
  my_strcpy(tetris->options->drop, "");
  my_strcpy(tetris->options->quit, "^E");
  my_strcpy(tetris->options->pause, " ");
}
