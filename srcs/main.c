/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Feb 27 23:39:59 2016 maud marel
** Last update Mon Feb 29 14:05:42 2016 maud marel
*/

#include "tetris.h"

int		main(int ac, char **av)
{
  t_tetris	tetris;
  int		i;

  init_tetris(&tetris);
  check_arg(&tetris, ac, av);
  return (0);
}
