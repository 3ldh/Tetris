/*
** my_strcpy.c for my_strcpy in /home/marel_m/rendu/Piscine_C_J06/ex_02
** 
** Made by maud marel
** Login   <marel_m@epitech.net>
** 
** Started on  Mon Oct  5 11:19:50 2015 maud marel
** Last update Mon Oct  5 16:55:30 2015 maud marel
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
