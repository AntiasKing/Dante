/*
** sorted_queue.h for dante in /home/antiaskid/Documents/B2/dante/astar/inc/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Fri Apr 28 18:48:32 2017 Antoine Briaux
** Last update Fri May 12 17:15:00 2017 Antoine Briaux
*/

#ifndef __SORTED_QUEUE__
# define __SORTED_QUEUE__

# include "maze.h"

typedef struct 	s_s_queue
{
	t_cell 		*tab;
	int 		nb_elem;
}				t_s_queue;

void 	init_s_queue(t_s_queue *s_queue, int size);
void 	insert_s_queue(t_s_queue *s_queue, int index, int eval);
int 	extract_s_queue(t_s_queue *s_queue);
void 	print_queue(t_s_queue *s_queue);

#endif /* ! __SORTED_QUEUE__ */
