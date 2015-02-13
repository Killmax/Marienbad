/*
** error.c for bsq in /home/brugue_m/rendu/CPE_2014_bsq
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Thu Jan 15 11:13:41 2015 bruguet Maxime
** Last update Mon Feb  9 11:21:19 2015 bruguet Maxime
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void		my_error(char *mes)
{
  write(2, mes, my_strlen(mes));
  exit(1);
}
