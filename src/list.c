/*
** list.c for ms1 in /home/brugue_m/rendu/PSU_2014_minishell1
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Tue Jan 20 13:48:08 2015 bruguet Maxime
** Last update Tue Feb 17 12:11:56 2015 bruguet Maxime
*/

#include <stdlib.h>
#include "my.h"

t_list		*create_list(void)
{
  t_list	*elem;

  elem = NULL;
  if ((elem = malloc(sizeof(*elem))) != NULL)
    {
      elem->length = 0;
      elem->tail = NULL;
      elem->head = NULL;
    }
  else
    my_error(MALLOC_FAIL);
  return (elem);
}

t_list		*put_in_list(t_list *list, char *data)
{
  t_node	*node;

  node = NULL;
  if ((node = malloc(sizeof(*node))) != NULL)
    {
      node->data = data;
      node->next = NULL;
      if (list->tail == NULL)
	{
	  node->prev = NULL;
	  list->head = node;
	  list->tail = node;
	}
      else
	{
	  list->tail->next = node;
	  node->prev = list->tail;
	  list->tail = node;
	}
      list->length++;
    }
  else
    my_error(MALLOC_FAIL);
  return (list);
}

void		free_list(t_list **list)
{
  t_node	*tmp;
  t_node	*del;

  tmp = NULL;
  del = NULL;
  tmp = (*list)->head;
  while (tmp != NULL)
    {
      del = tmp;
      tmp = tmp->next;
      free(del);
    }
  free(*list);
  *list = NULL;
}
