/*
** sorted_queue.c for dante in /home/antiaskid/Documents/B2/dante/astar/sorted_queue/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Fri Apr 28 18:47:42 2017 Antoine Briaux
** Last update Fri May 12 18:58:27 2017 Antoine Briaux
*/

# include <stdlib.h>
# include <stdio.h>
# include "maze.h"
# include "sorted_queue.h"

void 	init_s_queue(t_s_queue *s_queue, int size)
{
	int i;

	if (!(s_queue->tab = malloc(sizeof(t_cell) * size)))
		exit(84);
	i = 0;
	while (i < size)
	{
		s_queue->tab[i].eval = 1000000000;
		i++;
	}
	s_queue->nb_elem = 0;
}

void 		insert_s_queue(t_s_queue *s_queue, int pos, int eval)
{
	t_cell 	*tab;
	int 	index;
	int 	parent;
	t_cell 	tmp;

	tab = s_queue->tab;
	index = s_queue->nb_elem;
	parent = (index - 1) / 2;
	tab[index].pos = pos;
	tab[index].eval = eval;
	if (index >= 1)
	{
		while (tab[index].eval < tab[parent].eval)
		{
			tmp = tab[parent];
			tab[parent] = tab[index];
			tab[index] = tmp;
			index = parent;
			parent = (index - 1) / 2;
		}
	}
	s_queue->nb_elem++;
}

int 		extract_s_queue(t_s_queue *s_queue)
{
	int 	pos;
	t_cell	tmp;
	t_cell	*tab;

	tab = s_queue->tab;
	pos = tab[0].pos;
	if (s_queue->nb_elem > 1)
	{
		tab[0] = tab[--s_queue->nb_elem];
		while (tab[0].eval > tab[1].eval || tab[0].eval > tab[2].eval)
		{
			tmp = tab[0];
			if (tab[1].eval > tab[2].eval)
			{
				tab[0] = tab[2];
				tab[2] = tmp;
			}
			else
			{
				tab[0] = tab[1];
				tab[1] = tmp;
			}
		}
	}
	return (pos);
}

void 		print_queue(t_s_queue *s_queue)
{
	int 	i;

	i = 0;
	printf("Queue: \n");
	while (i < s_queue->nb_elem)
	{
		printf("i: %d, pos: %d,  eval: %d ", i,
			s_queue->tab[i].pos, s_queue->tab[i].eval);
		i++;
	}
	printf("\n");
}
