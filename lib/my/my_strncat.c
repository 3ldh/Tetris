/*
** my_strncat.c for my_strncat in /home/marel_m/rendu/Piscine_C_J07/lib/my
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Oct  6 15:49:14 2015 maud marel
** Last update Fri Mar 18 14:32:50 2016 
*/

#include "my.h"

char	*my_strncat(char *dest, char *src, int nb)
{
  int   l;
  int   dest_size;

  l = 0;
  dest_size = my_strlen(dest);
  while (src[l] != '\0' && l < nb)
    {
      dest[dest_size + l] = src[l];
      l = l + 1;
    }
  dest[dest_size + l] = '\0';
}
