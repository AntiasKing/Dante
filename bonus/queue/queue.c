/*
** queue.c for dante in /home/antiaskid/Documents/B2/dante/breadth/queue/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Tue Apr 18 16:42:42 2017 Antoine Briaux
** Last update Tue Apr 18 17:21:17 2017 Antoine Briaux
*/

# include <unistd.h>
# include <stdlib.h>
# include "queue.h"

void 		init_queue(t_queue *queue)
{
	queue->nb_node = 0;
	queue->first = NULL;
}

void 		push_queue(t_queue *queue, void *new_item)
{
	t_node 	*new_node;
	t_node 	*tmp;

	if (!(new_node = malloc(sizeof(t_node))))
		return;
	new_node->item = new_item;
	new_node->prec = NULL;
	new_node->next = NULL;
	queue->nb_node += 1;
	if (!queue->first)
		queue->first = new_node;
	else
	{
		tmp = queue->first;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->prec = tmp;
	}
}

void 		*top_queue(t_queue *queue)
{
	if (queue->nb_node <= 0)
	{
		write(1, "Error queue empty\n", 18);
		return (NULL);
	}
	return (queue->first->item);
}

void 		pop_queue(t_queue *queue)
{
	t_node	*to_free;

	if (queue->nb_node <= 0)
		write(1, "Error queue empty\n", 18);
	else
	{
		to_free = queue->first;
		queue->nb_node -= 1;
		if (queue->nb_node == 0)
			queue->first = NULL;
		else
		{
			queue->first = to_free->next;
			queue->first->prec = NULL;
		}
		if (to_free)
			free(to_free);
	}
}
