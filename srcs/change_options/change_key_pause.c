/*
** change_key_pause.c for change_key_pause in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:57:45 2016 maud marel
** Last update Wed Mar  2 17:43:04 2016 maud marel
*/

#include "tetris.h"

void	change_key_pause(t_tetris *tetris, char *str)
{
  int   i;

  i = 0;
  while (str[i] != '=' && str)
    i++;
  i++;
  if (i == my_strlen(str) || my_strlen(str) - i != 1)
    wrong_options();
  tetris->options->pause = str[i];
}

void	change_key_pause_simp(t_tetris *tetris, char *str)
{
  if (str[1] != '\0')
    wrong_options();
  tetris->options->pause = str[0];
}
