/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Feb 27 23:39:59 2016 maud marel
** Last update Sun Feb 28 23:17:39 2016 maud marel
*/

#include "tetris.h"

int		main(int ac, char **av)
{
  t_tetris	tetris;

  init_tetris(&tetris);
  printf("%s\n", av[1]);
  check_arg(&tetris, ac, av);
  return (0);
}
