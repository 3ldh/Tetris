/*
** check_high_score.c for check_high_score in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_tetris
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 17 11:16:54 2016
** Last update Fri Mar 18 23:00:26 2016 
*/

#include "tetris.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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
      free(nb);
      return (0);
    }
  data->high_score = my_getnbr(nb);
  free(nb);
  return (0);
}

int	count_nb(int nb)
{
  int	i;

  i = 1;
  while (nb > 0)
    {
      nb = nb / 10;
      i++;
    }
  return (i);
}

int	recup_high_score(t_tetris *data)
{
  int	fd;
  char *nb;
  char	*h_s;

  if ((h_s = malloc(sizeof(char) * (count_nb(data->score) + 1))) == NULL)
    return (-1);
  h_s = itoa(data->score, h_s, 10);
  if ((fd = open("high_score", O_RDONLY)) == -1)
    {
      fd = creat("high_score", 0644);
      write(fd, h_s, my_strlen(h_s));
      return (0);
    }
  nb = get_next_line(fd);
  if (nb == NULL || data->score > my_getnbr(nb))
    {
      fd = open("high_score", O_TRUNC | O_RDWR, 0644);
      write(fd, h_s, my_strlen(h_s));
      free(nb);
      return (0);
    }
  free(nb);
  return (0);
}
