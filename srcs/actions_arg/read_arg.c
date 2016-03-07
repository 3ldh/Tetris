/*
** read_arg.c for read_arg in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Mar  5 16:37:41 2016 maud marel
** Last update Mon Mar  7 13:35:46 2016 maud marel
*/

#include "tetris.h"

int	check_good_arg(t_tetris *tetris, char **av, int *i)
{
  int	n;

  n = 0;
  if ((av[(*i)][0] == '-' && av[(*i)][1] == '-')
      || my_strcmp(av[(*i)], "-w") == 0)
    n = check_complex_arg(tetris, av[(*i)]);
  else if (av[(*i)][0] == '-')
    {
      n = check_simp_arg(tetris, av[(*i)], av[(*i) + 1]);
      (*i)++;
    }
  else
    n = 1;
  return (n);
}

void    read_arg(t_tetris *tetris, int ac, char **av)
{
  int   i;
  int   n;
  int   debug;

  i = 0;
  n = 0;
  debug = 0;
  while (++i < ac)
    {
      if (my_strcmp(av[i], "-d") == 0 || my_strcmp(av[i], "--debug") == 0)
	debug = 1;
      else if (my_strcmp(av[i], "--help") == 0 && ac == 2)
	display_help(av[0]);
      else
	n = check_good_arg(tetris, av, &i);
      if (n == 1)
	{
	  my_putstr_error("Wrong arguments\n\n");
	  display_help_error();
	}
      }
  display_debug(tetris, debug);
}
