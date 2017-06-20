/*
** evaluate.c for dante in /home/antiaskid/Documents/B2/dante/astar/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Wed Apr 19 12:19:19 2017 Antoine Briaux
** Last update Fri May 12 17:49:02 2017 Antoine Briaux
*/

# include <stdlib.h>
# include "maze.h"
# include "evaluate.h"

int 		evaluate(t_maze *maze, int pos)
{
	static	int X_a = 0;
	static 	int Y_a = 0;

	if (X_a == 0)
		X_a = maze->length_x;
	if (Y_a == 0)
		Y_a = maze->length_total / maze->length_x;
	return (abs(pos % maze->length_x - X_a) + abs(pos / maze->length_x - Y_a));
}
