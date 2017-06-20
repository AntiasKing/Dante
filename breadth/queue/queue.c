/*
** queue.c for dante in /home/antiaskid/Documents/B2/dante/breadth/queue/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Tue Apr 18 16:42:42 2017 Antoine Briaux
** Last update Fri Apr 28 20:08:45 2017 Antoine Briaux
*/

# include <unistd.h>
# include <stdlib.h>
# include "queue.h"

void 		init_queue(t_queue *queue, int size)
{
	queue->tab = malloc(sizeof(int) * size);
	queue->nb_elem = 0;
	queue->first = 0;
}

void 		push_queue(t_queue *queue, int n)
{
	queue->tab[queue->nb_elem++] = n;
}

int 		top_queue(t_queue *queue)
{
	queue->nb_elem--;
	return (queue->tab[queue->first++]);
}
