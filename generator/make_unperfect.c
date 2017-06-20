/*
** make_unperfect.c for dante in /home/antiaskid/Documents/B2/dante/generator/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Fri Apr 14 17:37:21 2017 Antoine Briaux
** Last update Tue Apr 25 16:48:58 2017 Antoine Briaux
*/

# include "generator.h"
# include <stdlib.h>
# define POURCENT_UNPERFECT 10

void 	make_unperfect(t_maze *maze)
{
	int i;

	i = 0;
	while (i < maze->x * maze->y)
	{
		if (maze->maze[i].cell_maze == 'X')
		{
			if ((rand() % 100 + 1) <= POURCENT_UNPERFECT)
				maze->maze[i].cell_maze = '*';
		}
		i++;
	}
}
