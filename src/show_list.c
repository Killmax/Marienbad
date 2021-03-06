/*
** show_list.c for ms1 in /home/brugue_m/rendu/PSU_2014_minishell1
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Tue Jan 20 15:52:15 2015 bruguet Maxime
** Last update Sat Feb 21 17:09:35 2015 bruguet Maxime
*/

#include <stdlib.h>
#include "my.h"

void		put_space(char *data, int nb_line)
{
  int		i;

  i = 0;
  while (i < calc_space(my_strlen(data), nb_line))
    {
      my_putchar(' ');
      i++;
    }
}

void		show_list(t_list *list, int nb_line)
{
  t_node	*tmp;
  int		nb;

  if (list != NULL)
    {
      ascii_art();
      nb = 1;
      tmp = list->head;
      while (tmp != NULL)
	{
	  my_putnbr(nb++);
	  my_putchar(' ');
	  put_space(tmp->data, nb_line);
	  my_putstr(tmp->data);
	  put_space(tmp->data, nb_line);
	  my_putchar('\n');
	  tmp = tmp->next;
	}
      my_putchar('\n');
    }
}
