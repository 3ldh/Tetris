/*
** display_debug_key.c for display_debug_key in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
** 
** Made by maud marel
** Login   <marel_m@epitech.net>
** 
** Started on  Mon Mar  7 13:26:56 2016 maud marel
** Last update Mon Mar  7 17:32:49 2016 maud marel
*/

#include "tetris.h"

void	display_key(t_tetris *tetris)
{
  my_putstr("Key Left : ");
  my_putstr(tetris->options->left);
  my_putchar('\n');
  my_putstr("Key Right : ");
  my_putstr(tetris->options->right);
  my_putchar('\n');
  my_putstr("Key Turn : ");
  my_putstr(tetris->options->turn);
  my_putchar('\n');
  my_putstr("Key Drop : ");
  my_putstr(tetris->options->drop);
  my_putchar('\n');
  my_putstr("Key Quit : ");
  my_putstr(tetris->options->quit);
  my_putchar('\n');
  my_putstr("Key Pause : ");
  my_putstr(tetris->options->pause);
  my_putchar('\n');
}
