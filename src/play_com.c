/*
** play_com.c for allum1 in /home/brugue_m/rendu/Allum1
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Wed Feb 11 18:26:39 2015 bruguet Maxime
** Last update Tue Feb 17 13:20:35 2015 bruguet Maxime
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void		player(t_real *all)
{
  printf("A l'humain de jouer :\n");
  my_putstr("Sur quelle ligne voulez-vous supprimer ?\n");
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
  while (check_nbr_alum(all->nbr_alum, all->nb_line,
			(all->nb_alum = atoi(all->nbr))) == 1)
    {
      my_putstr("Combien d'alummette?\n");
      all->nb_alum = atoi((all->nbr = get_next_line(0)));
    }
  my_putchar('\n');
}

int		check_win_com(t_list *list, int cpt)
{
  t_node	*tmp;
  int		i;

  tmp = list->head;
  i = 0;
  while (tmp != NULL)
    {
      while (tmp->data[i])
	{
	  if (tmp->data[i] == '|')
	    return (FALSE);
	  else
	    i++;
	}
      tmp = tmp->next;
    }
  if (cpt % 2 == 1)
    my_putstr("L'humain a gagné !\n");
  else
    my_putstr("L'ordi a gagné !\n");
  exit(0);
  return (0);
}

void		computer(t_real *all)
{
  all->nb_line = rand() % NB_LINE + 1;
  while (all->nbr_alum[all->nb_line - 1] == 0)
    all->nb_line = rand() % NB_LINE + 1;
  all->nb_alum = rand() % (all->nbr_alum[all->nb_line - 1]) + 1;
  my_putchar('\n');
}

void		play_com(t_list *list)
{
  t_real		*all;

  all = NULL;
  all = init_all(all, list);
  show_list(list);
  while (all->is_win == FALSE)
    {
      if (nb_player(all->cpt) == 2)
	player(all);
      else
	computer(all);
      all->cpt++;
      list = delete_alum(all->nb_alum, all->nb_line, list);
      all->nbr_alum = stock_nbr(list);
      show_list(list);
      my_putstr("L'ordi est en train de jouer...\n");
      my_putstr("L'ordi a enlevé de manière hasardeuse ");
      printf("%d allumettes à la %de ligne\n", all->nb_alum, all->nb_line);
      all->is_win = check_win_com(list, all->cpt);
    }
}
