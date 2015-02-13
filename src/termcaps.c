/*
** termcaps.c for allum1 in /home/brugue_m/rendu/Allum1
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Mon Feb  9 16:05:39 2015 bruguet Maxime
** Last update Wed Feb 11 13:27:22 2015 bruguet Maxime
*/

#include <termios.h>
#include <term.h>
#include <unistd.h>
#include <ncurses/curses.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "my.h"

int		raw_mode(struct termios *t)
{
  t->c_lflag &= ~(ICANON);
  t->c_lflag &= ~(ECHO);
  t->c_cc[VMIN] = 1;
  t->c_cc[VTIME] = 0;
  if (tcsetattr(0,  TCSANOW, t) == -1)
    return (-1);
  return (0);
}

int		set_def(struct termios *t)
{
  t->c_lflag = (ICANON | ECHO);
  t->c_iflag = (IGNBRK);
  if (tcsetattr(0, 0, t) == -1)
    return (-1);
  tputs(tgetstr("ve", NULL), 0, my_outc);
  tputs(tgetstr("ue", NULL), 0, my_outc);
  tputs(tgetstr("se", NULL), 0, my_outc);
  return (0);
}

int		clear_term()
{
  char		*res;

  if ((res = tgetstr("cl", NULL)) == NULL)
    return (1);
  tputs(res, 0, my_outc);
  return (0);
}
