/*
** my_strncmp.c for my_select in /home/brugue_m/PSU_2014_my_select
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Tue Jan  6 17:40:58 2015 bruguet Maxime
** Last update Tue Feb 10 18:39:49 2015 bruguet Maxime
*/

#include <stdlib.h>

int		my_strncmp(char *s1, char *s2, int n)
{
  int		i;

  i = 0;
  while (i < n && s1[i] != '\0')
    {
      if ((s1[i] > s2[i]) || (s1[i] < s2[i]))
	return (s1[i] - s2[i]);
      i++;
    }
  return (0);
}
