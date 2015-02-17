/*
** check_win_boy.c for allum1 in /home/brugue_m/rendu/CPE_2014_allum1/src
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Tue Feb 17 23:23:40 2015 bruguet Maxime
** Last update Tue Feb 17 23:29:51 2015 bruguet Maxime
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int		check_win_boyard(t_boyard *all)
{
  int		i;

  i = 0;
  while (all->line[i])
    {
      if (all->line[i] == '|')
	return (FALSE);
      else
	i++;
    }
  printf("Le joueur %d a gagné !\n", nb_player(all->cpt));
  exit(0);
  return (TRUE);
}
