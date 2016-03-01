/*
** change_key_turn.c for change_key_turn in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:54:34 2016 maud marel
** Last update Tue Mar  1 22:15:29 2016 maud marel
*/

#include "tetris.h"

void	change_key_turn(t_tetris *tetris, char *str)
{
  int   i;

  i = 0;
  while (str[i] != '=' && str)
    i++;
  i++;
  if (i == my_strlen(str) || my_strlen(str) - i != 1)
    {
      write(2, "Wrong arg: --key-turn={K}\n", 26);
      exit(1);
    }
  tetris->options->turn = str[i];
}

void	change_key_turn_simp(t_tetris *tetris, char *str)
{
  if (str[1] != '\0')
    {
      write(2, "Wrong args: -kt 'K'\n", 19);
      exit(1);
    }
  tetris->options->turn = str[0];
}
