/*
** depth_first_search.c for dante in /home/antiaskid/Documents/B2/dante/depth/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Mon Apr 17 18:52:27 2017 Antoine Briaux
** Last update Fri May 12 19:26:19 2017 Antoine Briaux
*/

# include <stdio.h>
# include <stdlib.h>
# include "unistd.h"
# include "maze.h"
# include "sorted_queue.h"

void 			write_path(t_maze *maze, int n)
{
	int 		tmp;

	while (maze->item[n] != '0')
	{
		tmp = n;
		if (maze->item[tmp] == 'U')
			tmp -= maze->length_x;
		else if (maze->item[tmp] == 'D')
			tmp += maze->length_x;
		else if (maze->item[tmp] == 'R')
			tmp += 1;
		else
			tmp -= 1;
		maze->solved[n] = 'o';
		n = tmp;
	}
	maze->solved[0] = 'o';
	write(1, maze->solved, maze->length_total);
}

void 			astar(t_maze *maze, int x)
{
	t_s_queue	s_queue;
	int		 	current;

	init_s_queue(&s_queue, maze->length_total);
	maze->item[x] = '0';
	insert_s_queue(&s_queue, x, maze->length_total);
	while (s_queue.nb_elem > 0)
	{
		current = extract_s_queue(&s_queue);
		if (current == maze->length_total - 1)
		{
			write_path(maze, current);
			return;
		}
		check_neightbours(maze, current, &s_queue);
	}
	write(1, "no solution found\n", 18);
}
