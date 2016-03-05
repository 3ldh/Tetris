/*
** my_putchar.c for my_putchar in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris/lib/my
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar  4 20:54:44 2016 maud marel
** Last update Fri Mar  4 20:55:00 2016 maud marel
*/

#include <stdlib.h>

void	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    exit(1);
}
