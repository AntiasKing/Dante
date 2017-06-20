/*
** check_neightbours.c for dante in /home/antiaskid/Documents/B2/dante/depth/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Mon Apr 17 21:25:38 2017 Antoine Briaux
** Last update Thu Apr 27 18:47:29 2017 Antoine Briaux
*/

# include "maze.h"
# include "queue.h"

static int 	check_right(t_maze *maze, int pos)
{
	if (pos + 1 < maze->length_total &&
		(pos + 1) % maze->length_x < maze->length_x - 1 &&
		maze->item[pos + 1] == '*')
		return (1);
	return (0);
}

static int 	check_left(t_maze *maze, int pos)
{
	if (pos - 1 >= 0 && (pos - 1) % maze->length_x >= 0 &&
		maze->item[pos - 1] == '*')
		return (1);
	return (0);
}

static int 	check_up(t_maze *maze, int pos)
{
	if (pos - maze->length_x >= 0 && maze->item[pos - maze->length_x] == '*')
		return (1);
	return (0);
}

static int 	check_down(t_maze *maze, int pos)
{
	if (pos + maze->length_x < maze->length_total &&
		maze->item[pos + maze->length_x] == '*')
		return (1);
	return (0);
}

void 	check_neightbours(t_maze *maze, int pos, t_queue *queue)
{
	if (check_right(maze, pos))
	{
		maze->item[pos + 1] = 'L';
		push_queue(queue, (void *) ((long int) (pos + 1)));
	}
	if (check_down(maze, pos))
	{
		maze->item[pos + maze->length_x] = 'U';
		push_queue(queue, (void *) ((long int) (pos + maze->length_x)));
	}
	if (check_up(maze, pos))
	{
		maze->item[pos - maze->length_x] = 'D';
		push_queue(queue, (void *) ((long int) (pos - maze->length_x)));
	}
	if (check_left(maze, pos))
	{
		maze->item[pos - 1] = 'R';
		push_queue(queue, (void *) ((long int) (pos - 1)));
	}
}
