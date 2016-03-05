/*
** change_map_size.c for change_map_size in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:46:17 2016 maud marel
** Last update Fri Mar  4 21:35:49 2016 maud marel
*/

#include "tetris.h"

void	check_good_size(char *str, char c, int *i, int *nb)
{
  while (str[(*i)] != c)
    {
      if (str[(*i)] < '0' || str[(*i)] > '9')
	wrong_options(str);
      (*i)++;
      (*nb)++;
    }
}

void	check_if_size(char *str, int *i)
{
  (*i) = 0;
  while (str && str[(*i)] != '=')
    (*i)++;
  (*i)++;
  if ((*i) == my_strlen(str))
    wrong_options(str);
}

void	init_j_nb(int *j, int *nb, int i)
{
  (*j) = i;
  (*nb) = 0;
}

void	init_j_i(int *i, int *j)
{
  (*i) = (*j);
  (*j) = 0;
}

void	change_map_size(t_tetris *tetris, char *str)
{
  int   i;
  int   j;
  char	*tmp;
  int	nb;

  check_if_size(str, &i);
  init_j_nb(&j, &nb, i);
  check_good_size(str, ',', &i, &nb);
  if ((tmp = malloc(sizeof(char) * (nb + 1))) == NULL)
    exit(1);
  init_j_i(&i, &j);
  while (str[i] != ',')
    tmp[j++] = str[i++];
  tmp[j] = '\0';
  tetris->options->row = my_getnbr(tmp) + 2;
  i++;
  init_j_nb(&j, &nb, i);
  check_good_size(str, '\0', &i, &nb);
  if ((tmp = malloc(sizeof(char) * (nb + 1))) == NULL)
    exit(1);
  init_j_i(&i, &j);
  while (str[i] != '\0')
    tmp[j++] = str[i++];
  tmp[j] = '\0';
  tetris->options->col = my_getnbr(tmp) + 2;
}
