/*
** init_all.c for allum1 in /home/brugue_m/rendu/Allum1
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Thu Feb 12 15:44:51 2015 bruguet Maxime
** Last update Tue Feb 17 13:34:20 2015 bruguet Maxime
*/

#include <stdlib.h>
#include "my.h"

t_real		*init_all(t_real *all, t_list *list)
{
  if ((all = malloc(sizeof(t_real *))) == NULL)
      my_error(MALLOC_FAIL);
  all->nbr_alum = stock_nbr(list);
  all->is_win = FALSE;
  all->cpt = 0;
  return (all);
}
