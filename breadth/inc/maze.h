/*
** maze.h for dante in /home/antiaskid/Documents/B2/dante/depth/inc/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Mon Apr 17 21:27:14 2017 Antoine Briaux
** Last update Fri Apr 28 15:57:36 2017 Antoine Briaux
*/

#ifndef __MAZE__
# define __MAZE__

# include "queue.h"

typedef struct 	s_maze
{
	char 		*item;
	char 		*solved;
	int 		length_total;
	int 		length_x;
	int 		length_y;
}				t_maze;

void 	breadth_search(t_maze *maze, int x);
void 	check_neightbours(t_maze *maze, int pos, t_queue *queue);

# endif /* ! __MAZE__ */
