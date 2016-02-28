/*
** my_putstr.c for my_putstr.c in /PSU_2015_my_printf
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Thu Oct  1 17:06:54 2015 maud marel
** Last update Sun Feb 28 16:29:36 2016 maud marel
*/

void		my_putstr_error(char *str)
{
  long int	i;

  i = 0;
  while (str[i])
    {
      write(2, &str[i], 1);
      i++;
    }
}
