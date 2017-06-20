/*
** load_file.c for dante in /home/antiaskid/Documents/B2/dante/depth/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Fri Apr 14 17:54:49 2017 Antoine Briaux
** Last update Fri Apr 28 00:52:27 2017 Antoine Briaux
*/

# include <sys/mman.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "maze.h"

static char 		*get_file(char *name_file)
{
	int 			fd;
	char 			*str;
	struct stat 	buf;

	if ((stat(name_file, &buf)) == -1)
		exit(84);
	if ((fd = open(name_file, O_RDONLY)) == -1)
		exit(84);
	if ((str = (char *) mmap(NULL, buf.st_size, PROT_READ | PROT_WRITE,
		MAP_PRIVATE, fd, 0)) == (char *) MAP_FAILED)
		exit(84);
	close(fd);
	return (str);
}

void 				init_maze(t_maze *maze, char *name_file)
{
	maze->item = get_file(name_file);
	maze->length_total = strlen(maze->item);
	maze->length_x = strcspn(maze->item, "\n") + 1;
}
