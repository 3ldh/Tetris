/*
** change_key_drop.c for change_key_drop in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:55:33 2016 maud marel
** Last update Mon Feb 29 16:12:43 2016 maud marel
*/

#include "tetris.h"

void	change_key_drop(t_tetris *tetris, char *str)
{
  int	i;
  int	j;

  i = 0;
  while (str[i] != '=' && str)
    i++;
  i++;
  if (i == my_strlen(str) || my_strlen(str) - i != 1)
    {
      write(2, "Wrong arg: --key-drop={K}\n", 26);
      exit(1);
    }
  j = 0;
  if ((tetris->options->drop = malloc(sizeof(char))) == NULL)
    exit(1);
  while (str[i] != '\0')
    {
      tetris->options->drop[j++] = str[i];
      i++;
    }
  tetris->options->drop[j] = '\0';
}

void	change_key_drop_simp(t_tetris *tetris, char *str)
{
  int	i;

  if (str[1] != NULL)
    {
      write(2, "Wrong args: -kd 'K'\n", 19);
      exit(1);
    }
  if ((tetris->options->drop = malloc(sizeof(char))) == NULL)
    exit(1);
  i = -1;
  while (str[++i] != '\0' && str)
    tetris->options->drop[i] = str[i];
  tetris->options->drop[i] = '\0';
}
