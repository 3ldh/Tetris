/*
** stock.c for stock in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_bstetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Feb 23 17:01:48 2016 maud marel
** Last update Mon Feb 29 22:55:15 2016 maud marel
*/

#include <unistd.h>
#include "tetris.h"

int     check_form(t_list_tetri *tetris, int fd)
{
  char  *file;
  int   h;
  int   w;

  w = 0;
  if ((tetris->tetrimino.tetrimino = malloc(sizeof(char) * 1)) == NULL)
    return (-1);
  tetris->tetrimino.tetrimino[0] = '\0';
  while ((file = get_next_line(fd)) != NULL)
    {
      if ((tetris->tetrimino.tetrimino = my_realloc(tetris->tetrimino.tetrimino, my_strlen(file) + 1)) == NULL)
	exit(1);
      my_strcat(tetris->tetrimino.tetrimino, file);
      my_strcat(tetris->tetrimino.tetrimino, "\n");
    }
  return (0);
}

void	stock_elem(t_list_tetri *tetris, int j, int i, char *f_l)
{
  if (j == 0)
    tetris->tetrimino.width = f_l[i] - 48;
  else if (j == 1)
    tetris->tetrimino.height = f_l[i] - 48;
  else
    tetris->tetrimino.color = f_l[i] - 48;
}

int	check_info(char *f_l, t_list_tetri *tetris)
{
  int   i;
  int   j;

  i = 0;
  j = -1;
  while (++j < 3)
    {
      while (f_l[i] != ' ' && f_l[i] != '\0')
	{
	  stock_elem(tetris, j, i, f_l);
	  i++;
	}
    }
  return (0);
}

int	stock(char *file, t_tetris *tetris, int fd, char *name)
{
  t_list_tetri	*new;

  if ((new = malloc(sizeof(t_list_tetri))) == NULL)
    exit(1);
  new->prev = tetris->list_tetri;
  new->next = tetris->list_tetri->next;
  tetris->list_tetri->next->prev = new;
  tetris->list_tetri->next = new;
  if ((new->tetrimino.name = malloc(sizeof(char) * my_strlen(name))) == NULL)
    exit(1);
  my_strcpy(new->tetrimino.name, name);
  if (check_info(file, new) == -1)
    return (-1);
  if (check_form(new, fd) == -1)
    return (-1);
  return (0);
}
