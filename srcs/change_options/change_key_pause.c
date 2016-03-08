/*
** change_key_pause.c for change_key_pause in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:57:45 2016 maud marel
** Last update Tue Mar  8 09:39:30 2016 maud marel
*/

#include "tetris.h"

void	change_key_pause(t_tetris *tetris, char *str)
{
  int   i;
  int	j;

  i = 0;
  while (str && str[i] != '=')
    i++;
  i++;
  if (i == my_strlen(str))
    wrong_options(str);
  if ((tetris->options->pause = malloc(sizeof(char)
				       * my_strlen(str) - (i + 1))) == NULL)
    exit(1);
  j = 0;
  while (str[i] != '\0')
    {
      tetris->options->pause[j] = str[i];
      i++;
      j++;
    }
  tetris->options->pause[j] = '\0';
}

void	change_key_pause_simp(t_tetris *tetris, char *str)
{
  tetris->options->pause = my_strdup(str);
}
