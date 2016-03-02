/*
** put_in_list.c for put_in_list in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Mar  2 11:47:01 2016 maud marel
** Last update Wed Mar  2 11:52:08 2016 maud marel
*/

#include "tetris.h"

void    create_list(t_tetris *tetris)
{
  t_list_tetri  *new;

  if ((new = malloc(sizeof(t_list_tetri))) == NULL)
    exit(1);
  new->prev = new;
  new->next = new;
  tetris->list_tetri = new;
}

void    add_list_after(t_list_tetri *old, char *str)
{
  t_list_tetri  *new;

  if ((new = malloc(sizeof(t_list_tetri))) == NULL)
    exit(1);
  new->prev = old->prev;
  new->next = old;
  old->prev->next = new;
  old->prev = new;
}

t_list_tetri    *add_list_before(t_list_tetri *old)
{
  t_list_tetri  *new;

  if ((new = malloc(sizeof(t_list_tetri))) == NULL)
    exit(1);
  new->prev = old;
  new->next = old->next;
  old->next->prev = new;
  old->next = new;
  return (new);
}

void            show_list(t_list_tetri *elem)
{
  t_list_tetri  *elem_next;

  elem_next = elem->next;
  while (elem_next != elem)
    {
      printf("%s\n", elem_next->tetrimino->name);
      elem_next = elem_next->next;
    }
}
