/*
** main.c for allum1 in /home/brugue_m/rendu/Allum1
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Mon Feb  9 11:13:48 2015 bruguet Maxime
** Last update Sat Feb 21 17:27:16 2015 bruguet Maxime
*/

#include <ncurses/curses.h>
#include <term.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int		my_outc(int c)
{
  write(1, &c, 1);
  return (0);
}

int		ask_nb(void)
{
  char		*nbr;
  int		nb;

  clear_term();
  ascii_art();
  my_putstr("Bienvenue dans l'allum1 !\n");
  my_putstr("Choisissez un nombre de ligne entre 1 et 30 inclus :\n");
  while ((nbr = get_next_line(0)) == NULL || check_nbr(nbr) == 1)
    {
      my_putstr("Ce n'est pas un nombre valide\n");
      my_putstr("Choisissez un nombre de ligne entre 1 et 30 inclus :\n");
    }
  while ((nb = atoi(nbr)) < 1 || (nb = atoi(nbr)) > 30)
    {
      my_putstr("Le nombre doit etre compris entre 1 et 30\n");
      my_putstr("Choisissez un nombre de ligne entre 1 et 30 inclus :\n");
      while ((nbr = get_next_line(0)) == NULL || check_nbr(nbr) == 1)
	{
	  my_putstr("Ce n'est pas un nombre valide\n");
	  my_putstr("Choisissez un nombre de ligne entre 1 et 30 inclus :\n");
	}
    }
  return (nb);
}

int		main(int ac, char **av)
{
  int		i;
  int		nb_line;
  t_list	*list;
  char		*name;

  if (ac != 1)
    my_error("USAGE : /allum1\n");
  i = 0;
  list = create_list();
  if ((name = getenv("TERM")) == NULL)
    my_error("ERROR : Environment not found\n");
  if (tgetent(NULL, "xterm") == -1)
    my_error("ERROR : tgetent failure\n");
  nb_line = ask_nb();
  while (i < nb_line)
    {
      list = put_in_list(list, stock_line());
      i++;
    }
  clear_term();
  ascii_art();
  play(list, nb_line);
  (void)av;
  return (0);
}
