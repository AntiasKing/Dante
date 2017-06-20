/*
** maze.h for dante in /home/antiaskid/Documents/B2/dante/depth/inc/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Mon Apr 17 21:27:14 2017 Antoine Briaux
** Last update Fri May 12 19:21:45 2017 Antoine Briaux
*/

#ifndef __MAZE__
# define __MAZE__

typedef struct 	s_maze
{
	char 		*item;
	char 		*solved;
	int 		length_total;
	int 		length_x;
	int 		length_y;
}				t_maze;

typedef struct 	s_cell
{
	int 		pos;
	int 		eval;
}				t_cell;

# include "sorted_queue.h"

void 	astar(t_maze *maze, int x);
int 	evaluate(t_maze *maze, int pos);
void 	check_neightbours(t_maze *maze, int pos, t_s_queue *queue);

# endif /* ! __MAZE__ */
