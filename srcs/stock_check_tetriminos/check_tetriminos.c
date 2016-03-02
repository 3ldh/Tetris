/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_bstetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Feb 23 15:11:43 2016 maud marel
** Last update Tue Mar  1 11:30:31 2016 Mathieu Sauvau
*/

#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include "tetris.h"

void	create_list(t_tetris *tetris)
{
  t_list_tetri	*new;

  if ((new = malloc(sizeof(t_list_tetri))) == NULL)
    exit(1);
  new->prev = new;
  new->next = new;
  tetris->list_tetri = new;
}

void	add_list_before(t_list_tetri *old, char *str)
{
  t_list_tetri	*new;

  if ((new = malloc(sizeof(t_list_tetri))) == NULL)
    exit(1);
  new->prev = old->prev;
  new->next = old;
  old->prev->next = new;
  old->prev = new;
}

void	add_list_after(t_list_tetri *old, char *str)
{
}

void		stock_tetriminos(char *str, t_tetris *tetris)
{
  int		fd;
  char		*file;
  char		*way;

  if ((way = malloc(sizeof(char) * 11)) == NULL)
    exit(1);
  way = "tetriminos/";
  if ((way = my_realloc(way, my_strlen(str))) == NULL)
    exit(1);
  my_strcat(way, str);
  if ((fd = open(way, O_RDONLY)) == -1)
    exit(1);
  file = get_next_line(fd);
  stock(file, tetris, fd, str);
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
      write(2, "Wrong name of tetriminos\n", 25);
      exit(1);
    }
  if (name[i++] != 't' && name[i++] != 'e' &&
      name[i++] != 't' && name[i++] != 'r' &&
      name[i++] != 'i' && name[i++] != 'm' &&
      name[i++] != 'i' && name[i++] != 'n' &&
      name[i++] != 'o')
    {
      write(2, "Wrong name of tetriminos\n", 25);
      exit(1);
    }
  stock_tetriminos(name, tetris);
}

void		show_list(t_list_tetri *elem)
{
  t_list_tetri	*elem_next;

  elem_next = elem->next;
  while (elem_next != elem)
    {
      printf("%s\n", elem_next->tetrimino.name);
      elem_next = elem_next->next;
    }
}


void		check_tetriminos(t_tetris *tetris)
{
  DIR		*dirp;
  struct dirent	*entry;

  if ((dirp = opendir("tetriminos")) == NULL)
    {
      write(2, "Not existing directory tetriminos\n", 34);
      exit(1);
    }
  create_list(tetris);
  while ((entry = readdir(dirp)) != NULL)
    {
      if (entry->d_name[0] != '.')
	check_first(tetris, entry->d_name);
    }
}
