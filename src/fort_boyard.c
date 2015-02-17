/*
** fort_boyard.c for allum1 in /home/brugue_m/rendu/CPE_2014_allum1/src
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Tue Feb 17 16:55:04 2015 bruguet Maxime
** Last update Tue Feb 17 23:57:00 2015 bruguet Maxime
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char		*create_boyard(void)
{
  char		*line;
  int		i;

  if ((line = malloc(sizeof(char) * 21)) == NULL)
    my_error(MALLOC_FAIL);
  i = 0;
  while (i < 20)
    {
      line[i] = '|';
      i++;
    }
  line[i] = 0;
  return (my_strdup(line));
}

void		put_line(char *line)
{
  int		i;

  i = 0;
  while (line[i])
    {
      my_putchar(line[i]);
      my_putchar(' ');
      i++;
    }
  my_putchar('\n');
}

int		check_nbr_boyard(t_boyard *all)
{
  all->nb_alum = atoi(all->nbr);
  if (all->nb_alum > 3 || all->nb_alum < 1)
    {
      my_putstr("Vous pouvez enlever seulement 1 à 3 allumettes\n");
      return (1);
    }
  else if (all->nb_alum > all->nbr_alum)
    return (1);
  return (0);
}

t_boyard	*delete_boyard(t_boyard *all)
{
  int		num_alum;
  int		i;

  num_alum = atoi(all->nbr) - 1;
  i = num_alum;
  while (i < num_alum + all->nb_alum + 1)
    {
      if (i < my_strlen(all->line))
	all->line[i] = '.';
      i++;
    }
  all->nbr_alum -= all->nb_alum;
  return (all);
}

void		fort_boyard(void)
{
  t_boyard		*all;

  all = NULL;
  all = init_boyard(all);
  clear_term();
  put_line(all->line);
  while (all->is_win == FALSE)
    {
      printf("Joueur %d :\n", nb_player(all->cpt++));
      my_putstr("A partir de quelle allumette voulez-vous en enlever ?\n");
      check_real_boyard(all);
      while (check_nbr_boyard(all) == 1)
	{
	  my_putstr("Combien d'alummette?\n");
	  all->nb_alum = atoi((all->nbr = get_next_line(0)));
	}
      my_putchar('\n');
      all  = delete_boyard(all);
      clear_term();
      put_line(all->line);
      all->is_win = check_win_boyard(all);
    }
}
