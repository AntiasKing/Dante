/*
** draw_square.c for dante in /home/antiaskid/Documents/B2/dante/bonus/view/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Mon Apr 24 17:02:57 2017 Antoine Briaux
** Last update Tue Apr 25 16:03:11 2017 Antoine Briaux
*/

# include <SFML/Graphics.h>
# include "view.h"

static void 		my_put_pixel(t_framebuffer *framebuf, int posx,
						int posy, sfColor color)
{
	int             position;
	unsigned int    *pixel;

	position = (framebuf->width * posy + posx) * 4;
	pixel = (void *) &(framebuf->pixels[position]);
	if ((posx > 0 && posx < framebuf->width)
		&& (posy > 0 && posy < framebuf->height))
	{
		*pixel = (color.a << 24) | (color.b << 16) | (color.g << 8) | color.r;
		framebuf->pixels[position] = *pixel;
	}
}

void 	draw_square(t_view *view, int posx, int posy, sfColor color)
{
	int x;
	int y;

	x = posx;
	while (x < posx + SIZE)
	{
		y = posy;
		while (y < posy + SIZE)
		{
			my_put_pixel(&(view->framebuf), x, y, color);
			y++;
		}
		x++;
	}
}
