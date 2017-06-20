/*
** init.c for dante in /home/antiaskid/Documents/B2/dante/generator/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Fri Apr 14 15:04:21 2017 Antoine Briaux
** Last update Fri Apr 14 17:42:37 2017 Antoine Briaux
*/

# include <stdlib.h>
# include "generator.h"

void 		init_maze(t_maze *maze, int x, int y)
{
	int 	i;
	if (x <= 0 ||y <= 0)
		exit (84);
	maze->x = x;
	maze->y = y;
	if (!(maze->maze = malloc(sizeof(t_cell) * (x * y + 1))))
		return;
	maze->maze[0].cell_maze = '*';
	maze->maze[0].check = 1;
	i = 1;
	while (i < (x * y + 1))
	{
		maze->maze[i].cell_maze = 'X';
		maze->maze[i].check = 0;
		i++;
	}
	maze->active_cell = 0;
}

void 			init_new_active(t_active *new_active)
{
	int 		i;

	i = 0;
	while (i < 4)
	{
		new_active[i].new_active = -1;
		new_active[i].to_sup = -1;
		i++;
	}
}
