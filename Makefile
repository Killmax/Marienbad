##
## Makefile for allum1 in /home/brugue_m/rendu/Allum1
## 
## Made by bruguet Maxime
## Login   <brugue_m@epitech.net>
## 
## Started on  Mon Feb  9 12:53:02 2015 bruguet Maxime
## Last update Tue Feb 17 23:28:04 2015 bruguet Maxime
##

NAME	= allum1

SRC	= src/main.c \
	src/list.c \
	src/error.c \
	src/stock_line.c \
	src/show_list.c \
	src/my_put.c \
	src/calc_space.c \
	src/termcaps.c \
	src/get_term_name.c \
	src/my_strdup.c \
	src/my_strncmp.c \
	src/my_strcpy.c \
	src/play.c \
	src/my_str_isnum.c \
	src/get_next_line.c \
	src/play_real.c \
	src/check_nbr.c \
	src/count_pipe.c \
	src/init_all.c \
	src/play_com.c \
	src/check_real.c \
	src/fort_boyard.c \
	src/check_win_boy.c

OBJ	= $(SRC:.c=.o)

RM	= rm -f

CC	= gcc

CFLAGS	+= -I. -Wall -Wextra -lncurses
CFLAGS	+= -g

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
