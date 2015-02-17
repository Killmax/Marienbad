/*
** play_real.c for allum1 in /home/brugue_m/rendu/Allum1
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Tue Feb 10 17:15:34 2015 bruguet Maxime
** Last update Tue Feb 17 18:32:07 2015 bruguet Maxime
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char		*change_data(int nb_alum, char *line)
{
  int		i;

  i = 0;
  while (line[i] == '.')
    {
      i++;
      nb_alum++;
    }
  while (i < nb_alum)
    {
      if (i < my_strlen(line))
	line[i] = '.';
      i++;
    }
  return (line);
}

t_list		*delete_alum(int nb_alum, int nb_line, t_list *list)
{
  t_node	*tmp;
  int		i;

  tmp = list->head;
  i = 1;
  while (tmp != NULL && i <= nb_line)
    {
      if (i == nb_line)
	tmp->data = change_data(nb_alum, tmp->data);
      else
	tmp = tmp->next;
      i++;
    }
  return (list);
}

int		nb_player(int cpt)
{
  if (cpt % 2 == 0)
    return (1);
  else if (cpt % 2 == 1)
    return (2);
  return (0);
}

int		check_win(t_list *list, int cpt)
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
  printf("Le joueur %d a gagné !\n", nb_player(cpt));
  exit(0);
  return (0);
}

void		play_real(t_list *list)
{
  t_real		*all;

  all = NULL;
  all = init_all(all, list);
  show_list(list);
  while (all->is_win == FALSE)
    {
      printf("Joueur %d :\n", nb_player(all->cpt++));
      my_putstr("Sur quelle ligne voulez-vous supprimer ?\n");
      check_real(all);
      while (check_nbr_alum(all->nbr_alum, all->nb_line,
			    (all->nb_alum = atoi(all->nbr))) == 1)
	{
	  my_putstr("Combien d'alummette?\n");
	  all->nb_alum = atoi((all->nbr = get_next_line(0)));
	}
      my_putchar('\n');
      list = delete_alum(all->nb_alum, all->nb_line, list);
      all->nbr_alum = stock_nbr(list);
      show_list(list);
      all->is_win = check_win(list, all->cpt);
    }
}
