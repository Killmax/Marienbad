/*
** show_list.c for ms1 in /home/brugue_m/rendu/PSU_2014_minishell1
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Tue Jan 20 15:52:15 2015 bruguet Maxime
** Last update Thu Feb 12 17:19:21 2015 bruguet Maxime
*/

#include <stdlib.h>
#include "my.h"

void		put_space(char *data)
{
  int		i;

  i = 0;
  while (i < calc_space(my_strlen(data)))
    {
      my_putchar(' ');
      i++;
    }
}

void		show_list(t_list *list)
{
  t_node	*tmp;
  int		nb;

  if (list != NULL)
    {
      //      clear_term();
      nb = 1;
      tmp = list->head;
      while (tmp != NULL)
	{
	  my_putnbr(nb++);
	  my_putchar(' ');
	  put_space(tmp->data);
	  my_putstr(tmp->data);
	  put_space(tmp->data);
	  my_putchar('\n');
	  tmp = tmp->next;
	}
      my_putchar('\n');
    }
}
