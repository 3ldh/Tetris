/*
** stock_tetrimino.c for stock_tetrimino in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar  3 14:33:13 2016 maud marel
** Last update Sun Mar  6 18:53:56 2016 Mathieu Sauvau
*/

#include "tetris.h"

int	check_big_one(t_list_tetri *tetris)
{
  if (tetris->tetrimino->height > tetris->tetrimino->width)
    return (tetris->tetrimino->height);
  return (tetris->tetrimino->width);
}

int	copy_tetri(t_list_tetri *tetris, int *h, char *file, int max)
{
  int   i;
  int	w;

  w = 0;
  if (my_strlen(file) > w)
    w = my_strlen(file);
  if ((tetris->tetrimino->tetrimino[(*h)] = malloc(sizeof(char)
						   * (max + 1))) == NULL)
    exit(1);
  i = -1;
  while (file[++i] != '\0')
    {
      if ((file[i] != ' ' && file[i] != '*')
	  || i >= tetris->tetrimino->width)
        {
          tetris->tetrimino->width = 0;
          return (-1);
        }
      tetris->tetrimino->tetrimino[(*h)][i] = file[i];
    }
  tetris->tetrimino->tetrimino[(*h)][i] = '\0';
  if (tetris->tetrimino->height - 1 > (*h))
    (*h)++;
  return (w);
}

int	check_form(t_list_tetri *tetris, int fd)
{
  char  *file;
  int   h;
  int   w;
  int	max;

  h = 0;
  max = check_big_one(tetris);
  tetris->tetrimino->max = max;
  if ((tetris->tetrimino->tetrimino = malloc(sizeof(char*)
					     * max)) == NULL)
    exit(1);
  while ((file = get_next_line(fd)) != NULL)
    if ((w = copy_tetri(tetris, &h, file, max)) == -1)
      return (1);
  if (w != tetris->tetrimino->width || h != tetris->tetrimino->height - 1)
    {
      tetris->tetrimino->width = 0;
      return (1);
    }
  return (0);
}
