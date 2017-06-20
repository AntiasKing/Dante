##
## Makefile for generator in /home/antiaskid/Documents/B2/dante/generator/
##
## Made by Antoine Briaux
## Login   <antoine.briaux@epitech.eu>
##
## Started on  Thu Apr 13 18:08:18 2017 Antoine Briaux
## Last update Fri May 12 19:26:38 2017 Antoine Briaux
##

CC = gcc

RM = rm -f

CFLAGS += -W -Wall -Wextra -I./inc -ofast

SRC = 	main.c 	\
		astar.c 	\
		evaluate.c	\
		check_neightbours.c		\
		sorted_queue/sorted_queue.c 			\
		load_file.c

OBJ = $(SRC:.c=.o)

NAME = solver

all: $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
