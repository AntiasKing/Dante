/*
** main.c for dante in /home/antiaskid/Documents/B2/dante/generator/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Thu Apr 13 17:58:47 2017 Antoine Briaux
** Last update Sun May 14 23:27:40 2017 Antoine Briaux
*/

# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "generator.h"
# include "stack.h"

t_active  		get_neighbours(t_maze *maze)
{
	t_active	new_active[4];
	int 		random;

	init_new_active(new_active);
	check_neighbours(new_active, maze);
	if (new_active[0].new_active == -1 && new_active[1].new_active == -1 &&
		new_active[2].new_active == -1 && new_active[3].new_active == -1)
		return (new_active[0]);
	while (new_active[(random = rand() % 4)].new_active == -1);
	return (new_active[random]);
}

int 	check_cells(t_maze *maze)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (i < maze->x * maze->y)
	{
		if (!maze->maze[i].check)
			nb++;
		i++;
	}
	return (nb);
}

void 			gen_perfect(t_maze *maze, t_stack *stack)
{
	t_active 	new_active;

	while (stack->nb_item)
	{
		new_active = get_neighbours(maze);
		if (new_active.new_active != -1)
		{
			push_stack(stack, (void *) maze->active_cell);
			maze->maze[new_active.to_sup].cell_maze = '*';
			maze->maze[new_active.new_active].cell_maze = '*';
			maze->maze[new_active.new_active].check = 1;
			maze->active_cell = new_active.new_active;
		}
		else if (stack->nb_item > 0)
		{
			maze->active_cell = (long int) top_stack(stack);
			pop_stack(stack);
		}
	}
	if (!(maze->x % 2) || !(maze->y % 2))
		maze->maze[maze->x * maze->y - 1].cell_maze = '*';
	if (!(maze->x % 2) || !(maze->y % 2))
		maze->maze[maze->x * maze->y - 2].cell_maze = '*';
}

void 		write_maze(t_maze maze)
{
	int 	i;

	i = 0;
	while (i < maze.y * maze.x)
	{
		write(1, &(maze.maze[i].cell_maze), 1);
		maze.maze[i].check += '0';
		if (!((i + 1) % maze.x) && i < maze.y * maze.x - 1)
		{
			write(1, "\n", 1);
		}
		i++;
	}
}

int 		main(int ac, char **av)
{
	t_maze 	maze;
	t_stack stack;

	srand(time(NULL));
	if (ac < 2)
		return (84);
	init_maze(&maze, atoi(av[1]), atoi(av[2]));
	INIT_STACK(stack, maze.x * maze.y);
	push_stack(&stack, (void *) maze.active_cell);
	gen_perfect(&maze, &stack);
	if (ac == 3 || (ac >= 4 && strcmp(av[3], "perfect")))
		make_unperfect(&maze);
	write_maze(maze);
	free(maze.maze);
	free(stack.data);
	return (0);
}
