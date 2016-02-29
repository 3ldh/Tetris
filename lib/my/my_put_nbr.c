/*
** my_put_nbr.c for my_put_nbr in /lib/my
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Oct  6 11:02:44 2015 maud marel
** Last update Mon Feb 29 16:35:56 2016 maud marel
*/

int	size(int nb)
{
  int	i;

  i = 0;
  while (nb >= 10)
    {
      nb /= 10;
      i++;
    }
  return (i);
}

int	powerten(int nb)
{
  int	j;
  int	i;

  j = 10;
  i = size(nb);
  while (i > 1)
    {
      j *= 10;
      i--;
    }
  return (j);
}

int	general(int nb, int r, int j)
{
  while (r >= 1)
    {
      nb = r / j;
      my_putchar(nb + 48);
      if (nb < 10 && nb >= 1)
	{
	  while (j != 1)
	    {
	      my_putchar(48);
	      j = j / 10;
	    }
	}
      r = r % j;
      j = j / 10;
    }
}

int	my_put_nbr(int nb)
{
  int	r;
  int	j;

  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  j = powerten(nb);
  r = nb;
  if (nb == 0)
    my_putchar('0');
  if (nb < 10 && nb >= 1)
    {
      nb = nb % j;
      my_putchar(nb + 48);
    }
  if (nb >= 10)
    general(nb, r, j);
}
