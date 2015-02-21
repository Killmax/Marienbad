/*
** play.c for allum1 in /home/brugue_m/rendu/Allum1
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Mon Feb  9 17:14:27 2015 bruguet Maxime
** Last update Sat Feb 21 16:50:40 2015 bruguet Maxime
*/

#include <stdlib.h>
#include "my.h"

int		is_correct(char *choice)
{
  if (choice == NULL)
    return (1);
  else if (my_str_isnum(choice) == 1)
    return (1);
  else if (my_strncmp(choice, "1", 1) == 0)
    return (0);
  else if (my_strncmp(choice, "2", 1) == 0)
    return (0);
  else if (my_strncmp(choice, "3", 1) == 0)
    return (0);
  else
    return (1);
}

void		play(t_list *list, int nb)
{
  char		*choice;

  my_putstr("Bienvenue dans l'allum1 !\n");
  my_putstr("Quel mode voulez vous :\n");
  my_putstr("(1) Versus IA\n");
  my_putstr("(2) Versus Player\n");
  my_putstr("(3) Fort Boyard !\n");
  choice = get_next_line(0);
  while (is_correct(choice) == 1)
    choice = get_next_line(0);
  if (my_strncmp(choice, "1", 1) == 0)
    play_com(list, nb);
  else if (my_strncmp(choice, "2", 1) == 0)
    play_real(list, nb);
  else if (my_strncmp(choice, "3", 1) == 0)
    fort_boyard();
}
