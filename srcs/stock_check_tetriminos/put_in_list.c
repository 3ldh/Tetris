/*
** put_in_list.c for put_in_list in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Mar  2 11:47:01 2016 maud marel
** Last update Fri Mar  4 17:31:55 2016 maud marel
*/

#include "tetris.h"

void		create_list(t_tetris *tetris)
{
  t_list_tetri  *new;

  if ((new = malloc(sizeof(t_list_tetri))) == NULL)
    exit(1);
  new->prev = new;
  new->next = new;
  tetris->list_tetri = new;
}

t_list_tetri	*add_list_after(t_list_tetri *old)
{
  t_list_tetri  *new;

  if ((new = malloc(sizeof(t_list_tetri))) == NULL)
    exit(1);
  new->prev = old->prev;
  new->next = old;
  old->prev->next = new;
  old->prev = new;
  return (new);
}

t_list_tetri	*which_order(t_tetris *tetris, char *str)
{
  t_list_tetri	*new;
  t_list_tetri	*tmp;

  tmp = tetris->list_tetri->next;
  while (tmp != tetris->list_tetri && my_strcmp(str, tmp->tetrimino->name) > 0)
    tmp = tmp->next;
  new = add_list_after(tmp);
  return (new);
}
