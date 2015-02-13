/*
** stock_line.c for allum1 in /home/brugue_m/rendu/Allum1
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Mon Feb  9 11:34:09 2015 bruguet Maxime
** Last update Thu Feb 12 14:44:08 2015 bruguet Maxime
*/

#include <stdlib.h>
#include "my.h"

int		*stock_nbr(t_list *list)
{
  int		*nbr;
  int		i;
  t_node	*tmp;

  if ((nbr = malloc(sizeof(int) * NB_LINE + 1)) == NULL)
    my_error(MALLOC_FAIL);
  i = 0;
  tmp = list->head;
  while (i < NB_LINE && tmp != NULL)
    {
      nbr[i] = count_pipe(tmp->data);
      tmp = tmp->next;
      i++;
    }
  nbr[i] = -1;
  return (nbr);
}

char		*stock_line(void)
{
  int		i;
  static int	size = 1;
  char		*line;

  if ((line = malloc(sizeof(char) * size)) == NULL)
    my_error(MALLOC_FAIL);
  i = 0;
  while (i < size)
    line[i++] = '|';
  size += 2;
  line[i] = '\0';
  return (line);
}
