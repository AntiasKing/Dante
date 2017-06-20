/*
** generator.h for dante in /home/antiaskid/Documents/B2/dante/generator/inc/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Thu Apr 13 18:15:55 2017 Antoine Briaux
** Last update Sun May 14 23:27:32 2017 Antoine Briaux
*/

#ifndef __GENERATOR__
# define __GENERATOR__

typedef struct 	s_cell
{
	char 		cell_maze;
	char 		check;
}				t_cell;

typedef struct 	s_active
{
	int 		new_active;
	int 		to_sup;
}				t_active;

typedef struct 	s_maze
{
	t_cell 		*maze;
	int 		x;
	int			y;
	long int 	active_cell;
}				t_maze;

void 	init_maze(t_maze *maze, int x, int y);
void 	init_new_active(t_active *new_active);
void 	check_neighbours(t_active *new_active, t_maze *maze);
void 	make_unperfect(t_maze *maze);

#endif /* ! __GENERATOR__ */
