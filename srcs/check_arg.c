/*
** check_arg.c for check_arg in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Feb 27 23:40:47 2016 maud marel
** Last update Sun Feb 28 23:19:09 2016 maud marel
*/

#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

t_tab_com	init_tab_comp_arg()
{
  t_tab_com	tab;

  if ((tab = malloc(sizeof(int*) * 9)) == NULL)
    exit(1);
  tab[0] = &change_level;
  tab[1] = &change_key_left;
  tab[2] = &change_key_right;
  tab[3] = &change_key_turn;
  tab[4] = &change_key_drop;
  tab[5] = &change_key_quit;
  tab[6] = &change_key_pause;
  tab[7] = &change_map_size;
  tab[8] = &change_without_next;
  return (tab);
}

void		check_complex_arg(t_tetris *tetris, char *str, char *new)
{
  char		*opt[9];
  int		i;
  t_tab_com	fptrtab;

  opt[0] = "--level=";
  opt[1] = "--key-left=";
  opt[2] = "--key-right=";
  opt[3] = "--key-turn=";
  opt[4] = "--key-drop=";
  opt[5] = "--key-quit=";
  opt[6] = "--key-pause=";
  opt[7] = "--map-size=";
  opt[8] = "--without-next";
  i = -1;
  fptrtab = init_tab_comp_arg();
  while (++i < 9)
    if (my_strcmp(str, opt[i]) == 0)
      fptrtab[i](tetris, new);
}

t_tab_sim	init_tab_simp_arg()
{
  t_tab_sim	tab;

  if ((tab = malloc(sizeof(int*) * 8)) == NULL)
    exit(1);
  tab[0] = &change_level;
  tab[1] = &change_key_left;
  tab[2] = &change_key_right;
  tab[3] = &change_key_turn;
  tab[4] = &change_key_drop;
  tab[5] = &change_key_quit;
  tab[6] = &change_key_pause;
  tab[7] = &change_without_next;
  return (tab);
}

void	simple_arg(UNUSED t_tetris *tetris, UNUSED char *str, UNUSED char *new)
{
  char	*opt[9];

  opt[0] = "-l";
  opt[1] = "-kl";
  opt[2] = "-kr";
  opt[3] = "-kt";
  opt[4] = "-kd";
  opt[5] = "-kq";
  opt[6] = "-kp";
  opt[7] = "-w";
}

void	check_arg(t_tetris *tetris, int ac, char **av)
{
  int	i;
  int	debug;

  i = 0;
  debug = 0;
  while (++i < ac)
    {
      if (my_strcmp(av[i], "10") == 0)
	debug = 1;
      else if (my_strcmp(av[i], "--help") == 0
	       && ac == 2)
	display_help();
      else if (av[i][0] == '-' && av[i][1] == '-'
	       && av[i + 1][0] != '`')
	check_complex_arg(tetris, av[i], av[i + 1]);
      else if (av[i][0] == '-' && av[i][1] != '-')
	simple_arg(tetris, av[i], av[i + 1]);
      else
	{
	  write(2, "Wrong arguments\n", 16);
	  exit(1);
	}
    }
  if (debug == 1)
    display_debug(tetris);
}
