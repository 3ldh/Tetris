/*
** change_without_next.c for change_without_next in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:48:01 2016 maud marel
** Last update Mon Feb 29 15:17:41 2016 maud marel
*/

#include "tetris.h"

void	change_without_next(t_tetris *tetris, char *str)
{
  /* int   i; */
  /* int   j; */

  /* i = 0; */
  /* while (str[i] != '=' && str) */
  /*   i++; */
  /* i++; */
  /* if (i == my_strlen(str)) */
  /*   { */
  /*     write(2, "Wrong arg: --key-next={K}\n", 26); */
  /*     exit(1); */
  /*   } */
  /* j = 0; */
  /* if ((tetris->options->next = malloc(sizeof(char) * (my_strlen(str) - i))) == NULL) */
  /*   exit(1); */
  /* while (str[i] != '\0') */
  /*   { */
  /*     tetris->options->next[j++] = str[i]; */
  /*     i++; */
  /*   } */
  /* tetris->options->next[j] = '\0'; */
}

void	change_without_next_simp(t_tetris *tetris, char *str)
{
  /* int   i; */

  /* if ((tetris->options->next = malloc(sizeof(char) * my_strlen(str))) == NULL) */
  /*   exit(1); */
  /* i = -1; */
  /* while (str[++i] != '\0' && str) */
  /*   tetris->options->next[i] = str[i]; */
  /* tetris->options->next[i] = '\0'; */
}
