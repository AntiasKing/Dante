/*
** queue.h for dante in /home/antiaskid/Documents/B2/dante/breadth/inc/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Tue Apr 18 16:42:59 2017 Antoine Briaux
** Last update Tue Apr 18 16:59:06 2017 Antoine Briaux
*/

# ifndef __QUEUE__
# define __QUEUE__

typedef struct 		s_node
{
	void 			*item;
	struct s_node	*prec;
	struct s_node 	*next;
}					t_node;

typedef struct 	s_queue
{
	int 		nb_node;
	t_node 		*first;
}				t_queue;

void 		init_queue(t_queue *queue);
void 		push_queue(t_queue *queue, void *new_item);
void 		*top_queue(t_queue *queue);
void 		pop_queue(t_queue *queue);

# endif /* ! __QUEUE__ */
