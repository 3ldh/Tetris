/*
** my_putchar.c for my_putchar in /lib/my
** 
** Made by maud marel
** Login   <marel_m@epitech.net>
** 
** Started on  Tue Oct  6 10:59:17 2015 maud marel
** Last update Tue Oct 13 18:29:53 2015 maud marel
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}
