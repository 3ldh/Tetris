/*
** change_key_right.c for change_key_right in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:51:59 2016 maud marel
** Last update Tue Mar  1 22:14:59 2016 maud marel
*/

#include "tetris.h"

void	change_key_right(t_tetris *tetris, char *str)
{
  int   i;

  i = 0;
  while (str[i] != '=' && str)
    i++;
  i++;
  if (i == my_strlen(str) || my_strlen(str) - i != 1)
    {
      write(2, "Wrong arg: --key-right={K}\n", 27);
      exit(1);
    }
  tetris->options->right = str[i];
}

void	change_key_right_simp(t_tetris *tetris, char *str)
{
  if (str[1] != '\n')
    {
      write(2, "Wrong args: -kr 'K'\n", 20);
      exit(1);
    }
  tetris->options->right = str[0];
}
