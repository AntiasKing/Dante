/*
** depth_first_search.c for dante in /home/antiaskid/Documents/B2/dante/depth/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Mon Apr 17 18:52:27 2017 Antoine Briaux
** Last update Fri Apr 28 17:06:00 2017 Antoine Briaux
*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "stack.h"
# include "maze.h"

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

void 			depth_search(t_maze *maze, int x)
{
	t_stack		stack;
	int			tmp;

	INIT_STACK(stack, maze->length_total);
	maze->item[x] = '0';
	stack.data[stack.nb_item++] = x;
	while (stack.nb_item)
	{
		stack.nb_item--;
		tmp = stack.data[stack.nb_item];
		if (tmp == maze->length_total - 1)
		{
			write_path(maze, tmp);
			free(stack.data);
			return;
		}
		check_neightbours(maze, tmp, &stack);
	}
	write(1, "no solution found\n", 18);
}
