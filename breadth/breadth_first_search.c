/*
** depth_first_search.c for dante in /home/antiaskid/Documents/B2/dante/depth/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Mon Apr 17 18:52:27 2017 Antoine Briaux
** Last update Fri Apr 28 16:57:52 2017 Antoine Briaux
*/

# include <stdlib.h>
# include <unistd.h>
# include "maze.h"
# include "queue.h"

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

void 			breadth_search(t_maze *maze, int x)
{
	t_queue		queue;
	int 		current;

	init_queue(&queue, maze->length_total);
	maze->item[x] = '0';
	queue.tab[queue.nb_elem++] = x;
	while (queue.nb_elem != queue.first)
	{
		current = queue.tab[queue.first++];
		if (current == maze->length_total - 1)
		{
			write_path(maze, maze->length_total - 1);
			free(queue.tab);
			return;
		}
		else
			check_neightbours(maze, current, &queue);
	}
	write(1, "no solution found\n", 18);
}
