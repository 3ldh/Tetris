/*
** check_high_score.c for check_high_score in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_tetris
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 17 11:16:54 2016
** Last update Thu Mar 17 11:46:47 2016 
*/

#include "tetris.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	check_high_score(t_tetris *data)
{
  int	fd;
  char	*nb;

  if ((fd = open("high_score", O_RDONLY)) == -1)
    {
      data->high_score = 0;
      return (0);
    }
  nb = get_next_line(fd);
  if (nb == NULL)
    {
      data->high_score = 0;
      return (0);
    }
  data->high_score = my_getnbr(nb);
  return (0);
}

int	recup_high_score(t_tetris *data)
{
  int	fd;
  char *nb;

  if ((fd = open("high_score", O_RDONLY)) == -1)
    {
      fd = creat("high_score", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

      return (0);
    }
  nb = get_next_line(fd);
  if (nb == NULL || data->high_score > my_getnbr(nb))
    {
      fd = creat("high_score", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
      return (0);
    }
  return (0);
}
