/*
** change_key_right.c for change_key_right in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:51:59 2016 maud marel
** Last update Sat Mar  5 10:08:37 2016 maud marel
*/

#include "tetris.h"

void	change_key_right(t_tetris *tetris, char *str)
{
  int   i;
  int	j;

  i = 0;
  while (str[i] != '=' && str)
    i++;
  i++;
  if (i == my_strlen(str) || my_strlen(str) - i != 1)
    wrong_options(str);
  if ((tetris->options->right = malloc(sizeof(char) * my_strlen(str) - (i + 1))) == NULL)
    exit(1);
  j = 0;
  while (str[i] != '\0')
    {
      tetris->options->right[j] = str[i];
      i++;
      j++;
    }
  tetris->options->right[j] = '\0';
}

void	change_key_right_simp(t_tetris *tetris, char *str)
{
  if ((tetris->options->right = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    exit(1);
  my_strcpy(tetris->options->right, str);
}
