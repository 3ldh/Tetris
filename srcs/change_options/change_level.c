/*
** change_level.c for change_level in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:44:38 2016 maud marel
** Last update Sun Feb 28 22:09:03 2016 maud marel
*/

#include "tetris.h"

void	change_level(t_tetris *tetris, char *str)
{
  tetris->options->level = str;
}
