/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_bstetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Feb 23 15:11:43 2016 maud marel
** Last update Tue Mar  8 21:47:26 2016 maud marel
*/

#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include "tetris.h"

int		stock_tetriminos(char *str, t_tetris *tetris)
{
  int		fd;
  char		*file;
  char		*way;

  if ((way = my_strdup("tetriminos/")) == NULL
      || (way = my_realloc(way, my_strlen(str) + 1)) == NULL)
    return (-1);
  my_strcat(way, str);
  if ((fd = open(way, O_RDONLY)) == -1
      || (file = get_next_line(fd)) == NULL
      || stock(file, tetris, fd, str) == -1)
    return (-1);;
  free(way);
  while (get_next_line(fd) != NULL);
  if (close(fd) == -1)
    return (-1);
  return (0);
}

int	check_first(t_tetris *tetris, char *name)
{
  int	i;

  i = 0;
  while (name[i] != '.' && name[i] != '\0')
    i++;
  i++;
  if (name[i] == '\0')
    {
      my_putstr_error("Wrong name of tetriminos\n");
      return (-1);
    }
  if (name[i++] != 't' && name[i++] != 'e' &&
      name[i++] != 't' && name[i++] != 'r' &&
      name[i++] != 'i' && name[i++] != 'm' &&
      name[i++] != 'i' && name[i++] != 'n' &&
      name[i++] != 'o')
    {
      my_putstr_error("Wrong name of tetriminos\n");
      return (-1);
    }
  if (stock_tetriminos(name, tetris) == -1)
    return (-1);
  return (0);
}

int		check_tetriminos(t_tetris *tetris)
{
  DIR		*dirp;
  struct dirent	*entry;

  if ((dirp = opendir("tetriminos")) == NULL)
    {
      my_putstr_error("Not existing directory tetriminos\n");
      return (-1);
    }
  if (create_list(tetris) == -1)
    return (-1);
  tetris->list_tetri->nb_tetri = 0;
  while ((entry = readdir(dirp)) != NULL)
    if (entry->d_name[0] != '.')
      {
	tetris->list_tetri->nb_tetri++;
	check_first(tetris, entry->d_name);
      }
  return (0);
}
