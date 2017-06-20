/*
** check_neightbours.c for dante in /home/antiaskid/Documents/B2/dante/depth/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Mon Apr 17 21:25:38 2017 Antoine Briaux
** Last update Sun May 14 23:34:54 2017 Antoine Briaux
*/

# include <stdio.h>
# include "maze.h"
# include "stack.h"

void 	check_neightbours(t_maze *maze, int pos, t_stack *stack)
{
	if (pos - 1 >= 0 && maze->item[pos - 1] == '*')
	{
		maze->item[pos - 1] = 'R';
		stack->data[stack->nb_item++] = pos - 1;
	}
	if (pos - maze->length_x >= 0 && maze->item[pos - maze->length_x] == '*')
	{
		maze->item[pos - maze->length_x] = 'D';
		stack->data[stack->nb_item++] = pos - maze->length_x;
	}
	if (pos + 1 < maze->length_total && maze->item[pos + 1] == '*')
	{
		maze->item[pos + 1] = 'L';
		stack->data[stack->nb_item++] = pos + 1;
	}
	if (pos + maze->length_x < maze->length_total &&
		maze->item[pos + maze->length_x] == '*')
	{
		maze->item[pos + maze->length_x] = 'U';
		stack->data[stack->nb_item++] = pos + maze->length_x;
	}
}
