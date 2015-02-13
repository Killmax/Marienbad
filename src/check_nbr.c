/*
** check_nbr.c for allum1 in /home/brugue_m/rendu/Allum1
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Wed Feb 11 13:55:09 2015 bruguet Maxime
** Last update Thu Feb 12 15:05:11 2015 bruguet Maxime
*/

#include "my.h"

int		check_nbr(char *nbr)
{
  if (my_str_isnum(nbr) == 1 || nbr[0] == '\0')
    {
      my_putstr("Ce n'est pas un nombre valide\n");
      return (1);
    }
  return (0);
}

int		check_nbr_alum(int *nbr, int line, int nb_alum)
{
  if (nbr[line - 1] < nb_alum)
    return (1);
  return (0);
}
