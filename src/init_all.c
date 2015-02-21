/*
** init_all.c for allum1 in /home/brugue_m/rendu/Allum1
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Thu Feb 12 15:44:51 2015 bruguet Maxime
** Last update Sat Feb 21 17:14:02 2015 bruguet Maxime
*/

#include <stdlib.h>
#include "my.h"

t_boyard	*init_boyard(t_boyard *all)
{
  if ((all = malloc(sizeof(t_boyard *))) == NULL)
      my_error(MALLOC_FAIL);
  all->is_win = FALSE;
  all->cpt = 0;
  all->line = create_boyard();
  all->nbr_alum = 20;
  return (all);
}

t_real		*init_all(t_real *all, t_list *list, int nb_line)
{
  if ((all = malloc(sizeof(t_real *))) == NULL)
      my_error(MALLOC_FAIL);
  all->nbr_alum = stock_nbr(list, nb_line);
  all->is_win = FALSE;
  all->cpt = 0;
  return (all);
}
