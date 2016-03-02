/*
** init_options.c for init_options in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 19:30:09 2016 maud marel
** Last update Tue Mar  1 09:59:59 2016 Mathieu Sauvau
*/

#include "tetris.h"

void	init_tetris(t_tetris *tetris)
{
  if ((tetris->options = malloc(sizeof(t_options))) == NULL)
    exit(1);
  tetris->options->level = 1;
  tetris->options->row = 22;
  tetris->options->col = 12;
  tetris->options->hide_next = 0;
  if ((tetris->options->left = malloc(sizeof(char) * 4)) == NULL)
    exit(1);
  my_strcpy(tetris->options->left, "^E[C");
  if ((tetris->options->right = malloc(sizeof(char) * 4)) == NULL)
    exit(1);
  my_strcpy(tetris->options->right, "^E[D");
  if ((tetris->options->turn = malloc(sizeof(char) * 4)) == NULL)
    exit(1);
  my_strcpy(tetris->options->turn, "^E[A");
  if ((tetris->options->drop = malloc(sizeof(char) * 4)) == NULL)
    exit(1);
  my_strcpy(tetris->options->drop, "^E[B");
  if ((tetris->options->quit = malloc(sizeof(char) * 2)) == NULL)
    exit(1);
  my_strcpy(tetris->options->quit, "^E");
  if ((tetris->options->pause = malloc(sizeof(char) * 7)) == NULL)
    exit(1);
  my_strcpy(tetris->options->pause, "(space)");
}
