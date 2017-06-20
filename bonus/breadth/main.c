/*
** main.c for dante in /home/antiaskid/Documents/B2/dante/depth/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Fri Apr 14 17:53:39 2017 Antoine Briaux
** Last update Fri Apr 28 01:04:50 2017 Antoine Briaux
*/

# include <sys/mman.h>
# include <stdlib.h>
# include "view.h"
# include "load_file.h"
# include "maze.h"

int 		main(int ac, char **av)
{
	t_maze 	maze;
	t_view 	view;

	if (ac < 2)
		return (84);
	init_maze(&maze, av[1]);
	if (!maze.item)
		return (84);
	init_view(&view);
	breadth_search(&maze, 0, &view);
	munmap(maze.item, maze.length_total);
	return (0);
}
