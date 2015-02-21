/*
** calc_space.c for allum1 in /home/brugue_m/rendu/Allum1
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Mon Feb  9 13:19:02 2015 bruguet Maxime
** Last update Sat Feb 21 17:06:45 2015 bruguet Maxime
*/

#include "my.h"

int		size_last_line(int nb_line)
{
  int		i;
  int		size;

  i = 1;
  size = 1;
  while (i++ < nb_line)
    size += 2;
  return (size);
}

int		calc_space(int nb_alum, int nb_line)
{
  return ((size_last_line(nb_line) - nb_alum) / 2);
}
