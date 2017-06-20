/*
** check_neightbours.c for dante in /home/antiaskid/Documents/B2/dante/depth/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Mon Apr 17 21:25:38 2017 Antoine Briaux
** Last update Sun May 14 23:34:31 2017 Antoine Briaux
*/

# include "maze.h"
# include "queue.h"

void 	check_neightbours(t_maze *maze, int pos, t_queue *queue)
{
	if (pos + 1 < maze->length_total && maze->item[pos + 1] == '*')
	{
		maze->item[pos + 1] = 'L';
		queue->tab[queue->nb_elem++] = pos + 1;
	}
	if (pos + maze->length_x < maze->length_total &&
		maze->item[pos + maze->length_x] == '*')
	{
		maze->item[pos + maze->length_x] = 'U';
		queue->tab[queue->nb_elem++] = pos + maze->length_x;
	}
	if (pos - maze->length_x >= 0 && maze->item[pos - maze->length_x] == '*')
	{
		maze->item[pos - maze->length_x] = 'D';
		queue->tab[queue->nb_elem++] = pos - maze->length_x;
	}
	if (pos - 1 >= 0 && maze->item[pos - 1] == '*')
	{
		maze->item[pos - 1] = 'R';
		queue->tab[queue->nb_elem++] = pos - 1;
	}
}
