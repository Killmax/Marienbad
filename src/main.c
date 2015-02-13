/*
** main.c for allum1 in /home/brugue_m/rendu/Allum1
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Mon Feb  9 11:13:48 2015 bruguet Maxime
** Last update Thu Feb 12 15:28:22 2015 bruguet Maxime
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

int		main(int ac, char **av)
{
  int		i;
  t_list	*list;
  char		*name;

  if (ac != 1)
    my_error("USAGE : /allum1\n");
  i = 0;
  list = create_list();
  while (i < NB_LINE)
    {
      list = put_in_list(list, stock_line());
      i++;
    }
  if ((name = getenv("TERM")) == NULL)
    my_error("ERROR : Environment not found\n");
  if (tgetent(NULL, "xterm") == -1)
    my_error("ERROR : tgetent failure\n");
  clear_term();
  show_list(list);
  play(list);
  (void)av;
  return (0);
}
