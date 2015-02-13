/*
** calc_space.c for allum1 in /home/brugue_m/rendu/Allum1
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Mon Feb  9 13:19:02 2015 bruguet Maxime
** Last update Mon Feb  9 14:04:17 2015 bruguet Maxime
*/

#include "my.h"

int		size_last_line(void)
{
  int		i;
  int		size;

  i = 1;
  size = 1;
  while (i++ < NB_LINE)
    size += 2;
  return (size);
}

int		calc_space(int nb_alum)
{
  return ((size_last_line() - nb_alum) / 2);
}
