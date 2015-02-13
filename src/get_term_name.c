/*
** get_term_name.c for my_select in /home/brugue_m/PSU_2014_my_select
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Thu Jan  8 13:55:14 2015 bruguet Maxime
** Last update Mon Feb  9 16:32:25 2015 bruguet Maxime
*/

#include <stdlib.h>
#include "my.h"

char		*get_term_name(char **env)
{
  int		i;

  i = 0;
  while (env[i])
    {
      if (my_strncmp("TERM=", env[i], 5) == 0)
	return (my_strdup(env[i] + 5));
      else
	i++;
    }
  return (NULL);
}
