/*
** my_realloc.c for my_realloc in /home/marel_m/Rendu/Piscine_C/Piscine_C_workshoplib/lib/my
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Mon Nov 23 11:36:14 2015 maud marel
** Last update Fri Mar 18 14:33:08 2016 
*/

#include "my.h"
#include <stdlib.h>

char	*my_realloc(char *old, int size)
{
  char	*new;

  if ((new = malloc(sizeof(char *) *size)) == NULL)
    return (NULL);
  my_strcpy(new, old);
  free(old);
  return (new);
}
