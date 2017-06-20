/*
** evaluate.h for dante in /home/antiaskid/Documents/B2/dante/astar/inc/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Wed Apr 19 12:27:31 2017 Antoine Briaux
** Last update Wed Apr 19 12:29:05 2017 Antoine Briaux
*/

#ifndef __EVALUATE__
# define __EVALUATE__

int 	check_right(t_maze *maze, int pos);
int 	check_left(t_maze *maze, int pos);
int 	check_up(t_maze *maze, int pos);
int 	check_down(t_maze *maze, int pos);

#endif /* __EVALUATE__ */
