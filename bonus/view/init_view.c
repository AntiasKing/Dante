/*
** init_view->c for dante in /home/antiaskid/Documents/B2/dante/bonus/view/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Mon Apr 24 15:22:37 2017 Antoine Briaux
** Last update Fri Apr 28 01:03:08 2017 Antoine Briaux
*/

# include <stdlib.h>
# include "maze.h"
# include "view.h"

void 		init_view(t_view *view)
{
	int 	i;

	view->mode.width = SCENE_WIDTH;
	view->mode.height = SCENE_HEIGHT;
	view->mode.bitsPerPixel = SCENE_BPP;
	if (!(view->window = sfRenderWindow_create(view->mode,
		SCENE_NAME, sfClose, NULL)))
		return;
	if (!(view->texture = sfTexture_create(view->mode.width, view->mode.height)))
		return;
	if (!(view->sprite = sfSprite_create()))
		return;
	view->framebuf.width = SCENE_WIDTH;
	view->framebuf.height = SCENE_HEIGHT;
	if (!(view->framebuf.pixels = malloc(sizeof(sfUint8)
		* view->framebuf.width * view->framebuf.height * 4)))
		return;
	i = 0;
	while (i < view->framebuf.width * view->framebuf.height) {
		view->framebuf.pixels[i] = 0;
		i++;
	}
	sfSprite_setTexture(view->sprite, view->texture, sfTrue);
}

void 		destroy_view(t_view *view)
{
		sfSprite_destroy(view->sprite);
		sfTexture_destroy(view->texture);
		sfRenderWindow_destroy(view->window);
		free(view->framebuf.pixels);
}
