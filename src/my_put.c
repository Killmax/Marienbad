/*
** my_put.c for allum1 in /home/brugue_m/rendu/Allum1
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Mon Feb  9 12:59:03 2015 bruguet Maxime
** Last update Mon Feb  9 17:00:23 2015 bruguet Maxime
*/

#include <unistd.h>
#include "my.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void		my_putnbr(int nb)
{
  int		beg;
  int		end;

  end = nb % 10;
  beg = (nb - end) / 10;
  if (beg)
    my_putnbr(beg);
  my_putchar('0' + end);
}
