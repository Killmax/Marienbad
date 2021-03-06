/*
** my.h for allum1 in /home/brugue_m/rendu/Allum1
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Mon Feb  9 11:27:06 2015 bruguet Maxime
** Last update Sat Feb 21 17:21:00 2015 bruguet Maxime
*/

#ifndef MY_H_
# define MY_H_

# define NB_LINE 9
# define BUFF_SIZE 4096
# define TRUE 1
# define FALSE 0

# define MALLOC_FAIL "ERROR: can not allocate memory...\n"

typedef struct	s_node
{
  char		*data;
  struct s_node	*prev;
  struct s_node	*next;
}		t_node;

typedef struct	s_list
{
  int		length;
  struct s_node	*tail;
  struct s_node	*head;
}		t_list;

typedef struct	s_real
{
  char		is_win;
  int		nb_line;
  int		nb_alum;
  int		cpt;
  char		*nbr;
  int		*nbr_alum;
}		t_real;

typedef struct	s_boyard
{
  char		is_win;
  int		nb_alum;
  int		num_alum;
  int		nbr_alum;
  int		cpt;
  char		*line;
  char		*nbr;
}		t_boyard;

/*
** MY
*/

void		my_putchar(char);
void		my_putstr(char *);
int		my_strlen(char *);
int		my_outc(int);
void		my_putnbr(int);
char		*get_next_line(const int);
char		*get_term_name(char **env);
int		clear_term();
int		my_strncmp(char *, char *, int);
char		*my_strdup(char *);
char		*my_strcpy(char *, char *);
int		my_str_isnum(char *);

/*
** ALLUM1
*/

char		*stock_line(void);
void		play(t_list *, int);
int		calc_space(int, int);
void		play_real(t_list *, int);
int		count_pipe(char *);
int		*stock_nbr(t_list *, int);
int		check_nbr(char *);
int		check_nbr_alum(int *, int, int);
t_real		*init_all(t_real *, t_list *, int);
void		play_com(t_list *, int);
t_list		*delete_alum(int, int, t_list *);
int		nb_player(int);
void		check_real(t_real *, int);
int		check_cont_line(t_real *);
void		fort_boyard(void);
char		*create_boyard(void);
void		check_real_boyard(t_boyard *);
t_boyard	*init_boyard(t_boyard *);
int		check_win_boyard(t_boyard *);
void		ascii_art(void);
void		ascii_boyard(void);
void		ascii_noob(void);
void		ascii_win(void);

/*
** LINKED LIST
*/

t_list		*create_list(void);
t_list		*put_in_list(t_list *, char*);
void		free_list(t_list **);
void		show_list(t_list *, int);

/*
** ERROR
*/

void		my_error(char *);


#endif /* MY_H_ */
