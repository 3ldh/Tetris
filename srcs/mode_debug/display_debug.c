/*
** display_debug.c for display_debug in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:25:57 2016 maud marel
** Last update Sun Feb 28 23:26:47 2016 maud marel
*/

#include "tetris.h"

void	display_key(t_tetris *tetris)
{
  write(1, "Key Left : ", 11);
  write(1, tetris->options->left, 4);
  write(1, "\n", 1);
  write(1, "Key Right : ", 12);
  write(1, tetris->options->right, 4);
  write(1, "\n", 1);
  write(1, "Key Turn : ", 11);
  /* write(1, tetris->options->turn, my_strlen(tetris->options->turn)); */
  write(1, "\n", 1);
  write(1, "Key Drop : ", 11);
  /* write(1, tetris->options->drop, my_strlen(tetris->options->drop)); */
  write(1, "\n", 1);
  write(1, "Key Quit : ", 11);
  write(1, tetris->options->quit, 2);
  write(1, "\n", 1);
  write(1, "Key Pause : ", 11);
  /* write(1, tetris->options->pause, my_strlen(tetris->options->pause)); */
  write(1, "\n", 1);
}

void	display_more_info(t_tetris *tetris)
{
  write(1, "Next : ", 7);
  if (tetris->options->hide_next == 0)
    write(1, "Yes", 3);
  else
    write(1, "No", 2);
  write(1, "\n", 1);
  write(1, "Level : ", 8);
  write(1, tetris->options->level, 1);
  write(1, "\n", 1);
  write(1, "Size : ", 7);
  write(1, tetris->options->row, 2);
  write(1, "*", 1);
  write(1, tetris->options->col, 2);
  write(1, "\n", 1);
}

void	display_tetriminos(t_tetris *tetris)
{
}

void	display_debug(t_tetris *tetris)
{
  write(1, "*** DEBUG MODE ***\n", 19);
  display_key(tetris);
  display_more_info(tetris);
  display_tetriminos(tetris);
  write(1, "Press a key to start Tetris\n", 28);
}
