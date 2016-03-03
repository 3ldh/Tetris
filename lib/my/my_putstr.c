/*
** my_putstr.c for my_putstr.c in /lib/my
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Thu Oct  1 17:06:54 2015 maud marel
** Last update Thu Mar  3 13:27:50 2016 maud marel
*/

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
