/*
** maze.h for dante in /home/antiaskid/Documents/B2/dante/depth/inc/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Mon Apr 17 21:27:14 2017 Antoine Briaux
** Last update Mon Apr 24 17:42:26 2017 Antoine Briaux
*/

#ifndef __MAZE__
# define __MAZE__

# include "queue.h"

typedef struct 	s_maze
{
	char 		*item;
	int 		length_total;
	int 		length_x;
	int 		length_y;
}				t_maze;

# endif /* ! __MAZE__ */
