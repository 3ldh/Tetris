/*
** my_strncpy.c for my_strncpy in /home/marel_m/rendu/Piscine_C_J06/ex_03
** 
** Made by maud marel
** Login   <marel_m@epitech.net>
** 
** Started on  Mon Oct  5 11:17:08 2015 maud marel
** Last update Tue Oct 13 17:58:26 2015 maud marel
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n && src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
