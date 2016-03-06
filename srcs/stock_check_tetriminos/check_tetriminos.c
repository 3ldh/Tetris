/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_bstetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Feb 23 15:11:43 2016 maud marel
** Last update Sun Mar  6 16:01:41 2016 
*/

#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include "tetris.h"

void		stock_tetriminos(char *str, t_tetris *tetris)
{
  int		fd;
  char		*file;
  char		*way;

  if ((way = malloc(sizeof(char) * 12)) == NULL)
    exit(1);
  my_strcpy(way, "tetriminos/");
  if ((way = my_realloc(way, my_strlen(str) + 1)) == NULL)
    exit(1);
  my_strcat(way, str);
  if ((fd = open(way, O_RDONLY)) == -1)
    exit(1);
  if ((file = get_next_line(fd)) == NULL)
    exit(1);
  stock(file, tetris, fd, str);
  free(way);
  while (get_next_line(fd) != NULL);
  if (close(fd) == -1)
    exit(1);
}

void	check_first(t_tetris *tetris, char *name)
{
  int	i;

  i = 0;
  while (name[i] != '.' && name[i] != '\0')
    i++;
  i++;
  if (name[i] == '\0')
    {
      my_putstr_error("Wrong name of tetriminos\n");
      exit(1);
    }
  if (name[i++] != 't' && name[i++] != 'e' &&
      name[i++] != 't' && name[i++] != 'r' &&
      name[i++] != 'i' && name[i++] != 'm' &&
      name[i++] != 'i' && name[i++] != 'n' &&
      name[i++] != 'o')
    {
      my_putstr_error("Wrong name of tetriminos\n");
      exit(1);
    }
  stock_tetriminos(name, tetris);
}

void		check_tetriminos(t_tetris *tetris)
{
  DIR		*dirp;
  struct dirent	*entry;

  if ((dirp = opendir("tetriminos")) == NULL)
    {
      my_putstr_error("Not existing directory tetriminos\n");
      exit(1);
    }
  create_list(tetris);
  tetris->list_tetri->nb_tetri = 0;
  while ((entry = readdir(dirp)) != NULL)
    if (entry->d_name[0] != '.')
      {
	tetris->list_tetri->nb_tetri++;
	check_first(tetris, entry->d_name);
      }
}
