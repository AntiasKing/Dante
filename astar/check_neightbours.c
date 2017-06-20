/*
** check_neightbours.c for dante in /home/antiaskid/Documents/B2/dante/depth/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Mon Apr 17 21:25:38 2017 Antoine Briaux
** Last update Fri May 12 19:24:04 2017 Antoine Briaux
*/

# include "maze.h"
# include "sorted_queue.h"

int 	check_right(t_maze *maze, int pos)
{
	if (pos + 1 < maze->length_total && maze->item[pos + 1] == '*')
		return (1);
	return (0);
}

int 	check_left(t_maze *maze, int pos)
{
	if (pos - 1 >= 0 && maze->item[pos - 1] == '*')
		return (1);
	return (0);
}

int 	check_up(t_maze *maze, int pos)
{
	if (pos - maze->length_x >= 0 && maze->item[pos - maze->length_x] == '*')
		return (1);
	return (0);
}

int 	check_down(t_maze *maze, int pos)
{
	if (pos + maze->length_x < maze->length_total &&
		maze->item[pos + maze->length_x] == '*')
		return (1);
	return (0);
}

void 		check_neightbours(t_maze *maze, int pos, t_s_queue *s_queue)
{
	if (check_right(maze, pos))
	{
		maze->item[pos + 1] = 'L';
		insert_s_queue(s_queue, pos + 1, evaluate(maze, pos + 1));
	}
	if (check_down(maze, pos))
	{
		maze->item[pos + maze->length_x] = 'U';
		insert_s_queue(s_queue, pos + maze->length_x,
			evaluate(maze, pos + maze->length_x));
	}
	if (check_up(maze, pos))
	{
		maze->item[pos - maze->length_x] = 'D';
		insert_s_queue(s_queue, pos - maze->length_x,
			evaluate(maze, pos - maze->length_x));
	}
	if (check_left(maze, pos))
	{
		maze->item[pos - 1] = 'R';
		insert_s_queue(s_queue, pos - 1, evaluate(maze, pos - 1));
	}
}
