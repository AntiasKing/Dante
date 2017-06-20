/*
** stack.c for dante in /home/antiaskid/Documents/B2/dante/generator/stack/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Fri Apr 14 11:53:08 2017 Antoine Briaux
** Last update Fri Apr 28 17:13:21 2017 Antoine Briaux
*/

# include <unistd.h>
# include <stdlib.h>
# include "stack.h"

void 	init_stack(t_stack *stack, int size)
{
	if (!(stack->data = malloc(sizeof(void *) * size)))
		return;
	stack->size = size;
	stack->nb_item = 0;
}

void 	*top_stack(t_stack *stack)
{
	return (stack->data[stack->nb_item - 1]);
}

void 	push_stack(t_stack *stack, void *data)
{
	stack->data[stack->nb_item++] = data;
}

void 	pop_stack(t_stack *stack)
{
		stack->nb_item--;
}
