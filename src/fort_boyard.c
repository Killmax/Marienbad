/*
** fort_boyard.c for allum1 in /home/brugue_m/rendu/CPE_2014_allum1/src
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Tue Feb 17 16:55:04 2015 bruguet Maxime
** Last update Tue Feb 17 19:27:58 2015 bruguet Maxime
*/

#include "my.h"

char		*create_boyard(void)
{
  char		*line;
  int		i;

  if ((line = malloc(sizeof(char) * 21)) == NULL)
    my_error(MALLOC_FAIL);
  i = 0;
  while (line[i])
    {
      line[i] == '|';
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
}

t_boyard	*delete_boyard(t_boyard *all)
{
  int		i;
  int		nb_alum;

  i = 0;
  nb_alum = all->nb_alum;
  while (all->line[i] == '.')
    {
      i++;
      nb_alum++;
    }
  while (i < nb_alum)
    {
      if (i < my_strlen(line))
	all->line[i] = '.';
      i++;
    }
  return (all)
}

void		fort_boyard(t_list *list)
{
  t_boyard		*all;

  all = NULL;
  all = init_boyard(all);
  put_line(all->line);
  while (all->is_win == FALSE)
    {
      printf("Joueur %d :\n", nb_player(all->cpt++));
      my_putstr("A partir de quelle allumette voulez-vous en enlever ?\n");
      check_real(all);
      while (check_nbr_alum(all->nbr_alum, all->nb_line,
			    (all->nb_alum = atoi(all->nbr))) == 1)
	{
	  my_putstr("Combien d'alummette?\n");
	  all->nb_alum = atoi((all->nbr = get_next_line(0)));
	}
      my_putchar('\n');
      all  = delete_boyard(all);
      put_line(all->line);
      all->is_win = check_win_boyard(line, all->cpt);
    }
}
