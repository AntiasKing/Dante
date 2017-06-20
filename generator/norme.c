/*
** norme.c for dante in /home/antiaskid/Documents/B2/dante/generator/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Sun May 14 23:24:37 2017 Antoine Briaux
** Last update Sun May 14 23:27:20 2017 Antoine Briaux
*/

# include "generator.h"

void 	check_neighbours(t_active *new_active, t_maze *maze)
{
	if (maze->active_cell - 2 * maze->x > 0 &&
		!maze->maze[maze->active_cell - 2 * maze->x].check) {
			new_active[0].new_active = maze->active_cell - 2 * maze->x;
			new_active[0].to_sup = maze->active_cell - maze->x;
		}
	if (maze->active_cell + 2 < maze->x * maze->y &&
		maze->active_cell % maze->x < maze->x - 2 &&
		!maze->maze[maze->active_cell + 2].check) {
			new_active[1].new_active = maze->active_cell + 2;
			new_active[1].to_sup = maze->active_cell + 1;
		}
	if (maze->active_cell + 2 * maze->x < maze->x *maze->y &&
		!maze->maze[maze->active_cell + 2 * maze->x].check) {
			new_active[2].new_active = maze->active_cell + 2 * maze->x;
			new_active[2].to_sup = maze->active_cell + maze->x;
		}
	if (maze->active_cell - 2 > 0 && maze->active_cell % maze->x > 1
		&& !maze->maze[maze->active_cell - 2].check) {
			new_active[3].new_active = maze->active_cell - 2;
			new_active[3].to_sup = maze->active_cell - 1;
		}
}
