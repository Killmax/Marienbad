/*
** check_real.c for allum1 in /home/brugue_m/rendu/CPE_2014_allum1
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Sat Feb 14 16:22:01 2015 bruguet Maxime
** Last update Tue Feb 17 13:35:12 2015 bruguet Maxime
*/

#include <stdlib.h>
#include "my.h"

void		check_real(t_real *all)
{
  while ((all->nbr = get_next_line(0)) == NULL || check_nbr(all->nbr) == 1)
    my_putstr("Sur quelle ligne voulez-vous supprimer ?\n");
  while ((all->nb_line = atoi(all->nbr)) > NB_LINE || check_cont_line(all) == 1
	 || (all->nb_line = atoi(all->nbr)) <= 0)
    {
      my_putstr("Sur quelle ligne voulez-vous supprimer ?\n");
      all->nbr = get_next_line(0);
    }
  my_putstr("Combien d'alummette?\n");
  while ((all->nbr = get_next_line(0)) == NULL || check_nbr(all->nbr) == 1)
    my_putstr("Combien d'alummette?\n");
}