/*
** queue.h for dante in /home/antiaskid/Documents/B2/dante/breadth/inc/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Tue Apr 18 16:42:59 2017 Antoine Briaux
** Last update Fri Apr 28 15:37:48 2017 Antoine Briaux
*/

# ifndef __QUEUE__
# define __QUEUE__

typedef struct 	s_queue
{
	int 		*tab;
	int 		nb_elem;
	int 		first;
}				t_queue;

void 		init_queue(t_queue *queue, int size);
void 		push_queue(t_queue *queue, int n);
int 		top_queue(t_queue *queue);
void 		pop_queue(t_queue *queue);

# endif /* ! __QUEUE__ */
