/*
** my_strdup.c for my_strdup in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris/lib/my
** 
** Made by maud marel
** Login   <marel_m@epitech.net>
** 
** Started on  Tue Mar  8 09:15:03 2016 maud marel
** Last update Tue Mar  8 09:17:46 2016 maud marel
*/

#include <stdlib.h>

char	*my_strdup(char *str)
{
  char	*new;

  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  my_strcpy(new, str);
  return (new);
}
