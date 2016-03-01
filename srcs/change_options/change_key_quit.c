/*
** change_key_quit.c for change_key_quit in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:56:56 2016 maud marel
** Last update Tue Mar  1 09:38:08 2016 maud marel
*/

#include "tetris.h"

void	change_key_quit(t_tetris *tetris, char *str)
{
  int   i;
  int   j;

  i = 0;
  while (str[i] != '=' && str)
    i++;
  i++;
  if (i == my_strlen(str) || my_strlen(str) - i != 1)
    {
      write(2, "Wrong arg: --key-quit={K}\n", 26);
      exit(1);
    }
  j = 0;
  if ((tetris->options->quit = malloc(sizeof(char))) == NULL)
    exit(1);
  while (str[i] != '\0')
    {
      tetris->options->quit[j++] = str[i];
      i++;
    }
  tetris->options->quit[j] = '\0';
}

void	change_key_quit_simp(t_tetris *tetris, char *str)
{
  int   i;

  if (str[1] != '\0')
    {
      write(2, "Wrong args: -kq 'K'\n", 20);
    }
  if ((tetris->options->quit = malloc(sizeof(char))) == NULL)
    exit(1);
  i = -1;
  while (str[++i] != '\0' && str)
    tetris->options->quit[i] = str[i];
  tetris->options->quit[i] = '\0';
}
