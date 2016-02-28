/*
** my_strlen.c for my_strlen in /home/marel_m/Rendu/Systeme_Unix/PSU_2015_my_exec
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Jan  5 14:29:49 2016 maud marel
** Last update Sat Jan 23 21:47:36 2016 maud marel
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i])
    i++;
  return (i);
}
