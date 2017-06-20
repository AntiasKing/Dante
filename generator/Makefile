##
## Makefile for generator in /home/antiaskid/Documents/B2/dante/generator/
##
## Made by Antoine Briaux
## Login   <antoine.briaux@epitech.eu>
##
## Started on  Thu Apr 13 18:08:18 2017 Antoine Briaux
## Last update Sun May 14 23:26:18 2017 Antoine Briaux
##

CC = gcc

RM = rm -f

CFLAGS += -W -Wall -Wextra -I./inc -g3

SRC = 	main.c 	\
		stack/stack.c	\
		make_unperfect.c	\
		norme.c				\
		init.c

OBJ = $(SRC:.c=.o)

NAME = generator

all: $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
