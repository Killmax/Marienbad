/*
** lel.c for allum1 in /home/brugue_m/rendu/Allum1
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Thu Feb 12 14:29:58 2015 bruguet Maxime
** Last update Thu Feb 12 14:36:23 2015 bruguet Maxime
*/

#include "my.h"

int		count_pipe(char *line)
{
  int		cpt;
  int		i;

  cpt = 0;
  i = 0;
  while (line[i])
    {
      if (line[i] == '|')
	cpt++;
      i++;
    }
  return (cpt);
}
