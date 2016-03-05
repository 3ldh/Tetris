/*
** change_key_turn.c for change_key_turn in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:54:34 2016 maud marel
** Last update Sat Mar  5 10:10:05 2016 maud marel
*/

#include "tetris.h"

void	change_key_turn(t_tetris *tetris, char *str)
{
  int   i;
  int	j;

  i = 0;
  while (str && str[i] != '=')
    i++;
  i++;
  if (i == my_strlen(str))
    wrong_options(str);
  if ((tetris->options->turn = malloc(sizeof(char) * my_strlen(str) - (i + 1))) == NULL)
    exit(1);
  j = 0;
  while (str[i] != '\0')
    {
      tetris->options->turn[j] = str[i];
      i++;
      j++;
    }
  tetris->options->turn[j] = '\0';
}

void	change_key_turn_simp(t_tetris *tetris, char *str)
{
  if ((tetris->options->turn = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    exit(1);
  my_strcpy(tetris->options->turn, str);
}
