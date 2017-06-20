/*
** main.c for dante in /home/antiaskid/Documents/B2/dante/depth/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Fri Apr 14 17:53:39 2017 Antoine Briaux
** Last update Tue Jun  6 17:11:10 2017 Antoine Briaux
*/

# include <sys/mman.h>
# include <stdlib.h>
# include "load_file.h"
# include "maze.h"
# include "view.h"

void 	depth_search(t_maze *maze, int x, t_view *view);

int 		main(int ac, char **av)
{
	t_maze 	maze;
	t_view	view;
	sfImage *screen;

	if (ac < 2)
		return (84);
	init_maze(&maze, av[1]);
	if (!maze.item)
		return (-84);
	init_view(&view);
	depth_search(&maze, 0, &view);
	screen = sfImage_createFromPixels(SCENE_WIDTH,
		SCENE_HEIGHT, view.framebuf.pixels);
	sfImage_saveToFile(screen, "./Solved.tga");
	destroy_view(&view);
	munmap(maze.item, maze.length_total);
	return (0);
}
