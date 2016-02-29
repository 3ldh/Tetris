/*
** change_key_pause.c for change_key_pause in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:57:45 2016 maud marel
** Last update Mon Feb 29 16:12:59 2016 maud marel
*/

#include "tetris.h"

void	change_key_pause(t_tetris *tetris, char *str)
{
  int   i;
  int   j;

  i = 0;
  while (str[i] != '=' && str)
    i++;
  i++;
  if (i == my_strlen(str) || my_strlen(str) - i != 1)
    {
      write(2, "Wrong arg: --key-pause={K}\n", 27);
      exit(1);
    }
  j = 0;
  if ((tetris->options->pause = malloc(sizeof(char))) == NULL)
    exit(1);
  while (str[i] != '\0')
    {
      tetris->options->pause[j++] = str[i];
      i++;
    }
  tetris->options->pause[j] = '\0';
}

void	change_key_pause_simp(t_tetris *tetris, char *str)
{
  int   i;

  if (str[1] != NULL)
    {
      write(2, "Wrong args: -kp 'K'\n", 20);
      exit(1);
    }
  if ((tetris->options->pause = malloc(sizeof(char))) == NULL)
    exit(1);
  i = -1;
  while (str[++i] != '\0' && str)
    tetris->options->pause[i] = str[i];
  tetris->options->pause[i] = '\0';
}
