/*
** main.c for dante in /home/antiaskid/Documents/B2/dante/depth/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Fri Apr 14 17:53:39 2017 Antoine Briaux
** Last update Fri Apr 28 20:02:02 2017 Antoine Briaux
*/

# include <sys/mman.h>
# include <stdlib.h>
# include "load_file.h"
# include "maze.h"

int 		main(int ac, char **av)
{
	t_maze 	maze;

	if (ac < 2)
		return (84);
	init_maze(&maze, av[1]);
	if (!maze.item)
		return (84);
	astar(&maze, 0);
	munmap(maze.item, maze.length_total);
	return (0);
}
