/*
** my_strcat.c for my_strcat in /home/marel_m/rendu/Piscine_C_J07/lib/my
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Oct  6 14:22:38 2015 maud marel
** Last update Tue Mar  1 09:55:46 2016 maud marel
*/

char	*my_strcat(char *dest, char *src)
{
  int   l;
  int	dest_size;

  l = 0;
  dest_size = my_strlen(dest);
  while (src[l] != '\0' && src)
    {
      dest[dest_size + l] = src[l];
      l = l + 1;
    }
  dest[dest_size + l] = '\0';
  return (dest);
}