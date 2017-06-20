/*
** maze.h for dante in /home/antiaskid/Documents/B2/dante/depth/inc/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Mon Apr 17 21:27:14 2017 Antoine Briaux
** Last update Fri Apr 28 01:35:53 2017 Antoine Briaux
*/

#ifndef __MAZE__
# define __MAZE__

# include "stack.h"

typedef struct 	s_maze
{
	char 		*item;
	char 		*solved;
	int 		length_total;
	int 		length_x;
	int 		length_y;
}				t_maze;

void 	depth_search(t_maze *maze, int x);
void 	check_neightbours(t_maze *maze, int pos, t_stack *stack);

# endif /* ! __MAZE__ */
