/*
** change_key_quit.c for change_key_quit in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:56:56 2016 maud marel
** Last update Wed Mar  2 17:43:22 2016 maud marel
*/

#include "tetris.h"

void	change_key_quit(t_tetris *tetris, char *str)
{
  int   i;

  i = 0;
  while (str[i] != '=' && str)
    i++;
  i++;
  if (i == my_strlen(str) || my_strlen(str) - i != 1)
    wrong_options();
  tetris->options->quit = str[i];
}

void	change_key_quit_simp(t_tetris *tetris, char *str)
{
  if (str[1] != '\0')
    wrong_options();
  tetris->options->quit = str[0];
}
