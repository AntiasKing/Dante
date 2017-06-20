/*
** render.c for dante in /home/antiaskid/Documents/B2/dante/bonus/view/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Mon Apr 24 15:17:36 2017 Antoine Briaux
** Last update Tue Jun  6 17:16:49 2017 Antoine Briaux
*/

# include "view.h"
# include "maze.h"

void 	update(t_view *view, t_maze *map)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < map->length_total)
	{
		x = i % map->length_x;
		y = i / map->length_x;
		if (map->item[i] == 'X')
			draw_square(view, x * SIZE,
				y * SIZE, sfBlack);
		else if (map->item[i] == '*')
			draw_square(view, x * SIZE,
				y * SIZE, sfWhite);
		else if (map->item[i] == 'o')
			draw_square(view, x * SIZE,
				y * SIZE, sfGreen);
		else if (map->item[i] == 'U' || map->item[i] == 'L'
		|| map->item[i] == 'R' || map->item[i] == 'D' || map->item[i] == '0')
			draw_square(view, x * SIZE,
				y * SIZE, sfBlue);
		i++;

	}
}

void 		update_render(t_view *view, t_maze *map)
{	sfEvent event;

	while (sfRenderWindow_pollEvent(view->window, &event))
	{
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(view->window);
	}
	update(view, map);
	sfTexture_updateFromPixels(view->texture, view->framebuf.pixels,
		 SCENE_WIDTH, SCENE_HEIGHT, 0, 0);
	sfRenderWindow_clear(view->window, sfBlack);
	sfRenderWindow_drawSprite(view->window, view->sprite, NULL);
	sfRenderWindow_display(view->window);
}
