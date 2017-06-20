##
## Makefile for generator in /home/antiaskid/Documents/B2/dante/generator/
##
## Made by Antoine Briaux
## Login   <antoine.briaux@epitech.eu>
##
## Started on  Thu Apr 13 18:08:18 2017 Antoine Briaux
## Last update Tue Jun  6 16:53:28 2017 Antoine Briaux
##

CC = gcc

RM = rm -f

CFLAGS += -W -Wall -Wextra -I../inc -ofast

LDFLAGS	= -lc_graph_prog_full

SRC = 	main.c 	\
		depth_first_search.c 	\
		check_neightbours.c		\
		../stack/stack.c		\
		../load_file.c			\
		../view/draw_square.c		\
		../view/init_view.c		\
		../view/render.c

OBJ = $(SRC:.c=.o)

NAME = solver

all: $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
