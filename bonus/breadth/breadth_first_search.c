/*
** depth_first_search.c for dante in /home/antiaskid/Documents/B2/dante/depth/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Mon Apr 17 18:52:27 2017 Antoine Briaux
** Last update Tue Jun  6 17:14:37 2017 Antoine Briaux
*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "view.h"
# include "maze.h"
# include "queue.h"

void 	check_neightbours(t_maze *maze, int pos, t_queue *queue);

void 			write_path(t_maze *maze, int n, t_view *view)
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
		maze->item[n] = 'o';
		n = tmp;
		update_render(view, maze);
	}
	maze->item[0] = 'o';
	update_render(view, maze);
	sleep(10);
	exit(0);
}

void 			breadth_search(t_maze *maze, int x, t_view *view)
{
	t_queue		queue;
	long int 	current;

	init_queue(&queue);
	maze->item[x] = '0';
	push_queue(&queue, (void *) ((long int) x));
	while (queue.nb_node > 0)
	{
		current = (long int) top_queue(&queue);
		pop_queue(&queue);
		if (current == maze->length_total - 1)
		{
			write_path(maze, current, view);
			break;
		}
		else
			check_neightbours(maze, current, &queue);
		update_render(view, maze);
	}
	sleep(3);
	destroy_view(view);
}
