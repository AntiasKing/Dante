/*
** stack.c for dante in /home/antiaskid/Documents/B2/dante/generator/stack/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Fri Apr 14 11:49:03 2017 Antoine Briaux
** Last update Sun May 14 23:35:55 2017 Antoine Briaux
*/

#ifndef __MY_STACK__
# define __MY_STACK__

// # define MAX_STACK 10000

typedef struct s_stack
{
 	int 		*data;
	int 		size;
	int 		nb_item;
}				t_stack;

void 	init_stack(t_stack *stack, int size);
void 	*top_stack(t_stack *stack);
void 	push_stack(t_stack *stack, void *data);

# define INIT_STACK(stack, size) 	init_stack(&stack, size)
# define TOP_STACK(stack) 			top_stack(&stack)
# define PUSH_STACK(stack, data)	push_stack(stack, (void *) data)

#endif /* ! __MY_STACK__ */
