/*
** change_level.c for change_level in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:44:38 2016 maud marel
** Last update Sun Mar  6 16:05:49 2016 
*/

#include "tetris.h"

void	change_level(t_tetris *tetris, char *str)
{
  int   i;
  int   j;
  char	*tmp;

  i = 0;
  while (str[i] != '=' && str)
    i++;
  i++;
  if (i == my_strlen(str))
    wrong_options(str);
  j = 0;
  if ((tmp = malloc(sizeof(char) * (my_strlen(str) - i))) == NULL)
    exit(1);
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	wrong_options(str);
      tmp[j++] = str[i];
      i++;
    }
  tmp[j] = '\0';
  tetris->options->level = my_getnbr(tmp);
  free(tmp);
}

void	change_level_simp(t_tetris *tetris, char *str)
{
  int   i;
  char	*tmp;

  if ((tmp = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    exit(1);
  i = -1;
  while (str[++i] != '\0' && str)
    {
      if (str[i] < '0' || str[i] > '9')
	wrong_options(str);
      tmp[i] = str[i];
    }
  tmp[i] = '\0';
  tetris->options->level = my_getnbr(tmp);
  free(tmp);
}
