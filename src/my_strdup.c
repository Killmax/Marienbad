/*
** my_strdup.c for my_select in /home/brugue_m/PSU_2014_my_select
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Wed Jan  7 13:47:48 2015 bruguet Maxime
** Last update Mon Feb  9 16:42:56 2015 bruguet Maxime
*/

#include <stdlib.h>
#include "my.h"

char		*my_strdup(char *str)
{
  char		*dest;

  dest = (char *)malloc(sizeof(char) * my_strlen(str) + 1);
  dest = my_strcpy(dest, str);
  dest[my_strlen(str)] = 0;
  return (dest);
}
