/*
** stack.c for dante in /home/antiaskid/Documents/B2/dante/generator/stack/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Fri Apr 14 11:53:08 2017 Antoine Briaux
** Last update Sun May 14 23:35:47 2017 Antoine Briaux
*/

# include <unistd.h>
# include <stdlib.h>
# include "stack.h"

void 	init_stack(t_stack *stack, int size)
{
	if (!(stack->data = malloc(sizeof(int) * size)))
		return;
	stack->size = size;
	stack->nb_item = 0;
}
