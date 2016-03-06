/*
** my_power_rec.c for my_power_rec.c in /lib/my
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Fri Oct  2 14:26:26 2015 maud marel
** Last update Sat Mar  5 15:33:56 2016 maud marel
*/

int	my_power_rec(int nb, int power)
{
  if (power < 0)
    nb = 0;
  if (power == 0)
    nb = 1;
  power = power - 1;
  if (power > 0)
    nb = nb * my_power_rec(nb, power);
  return (nb);
}
