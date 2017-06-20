/*
** view.h for dante in /home/antiaskid/Documents/B2/dante/bonus/inc/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Mon Apr 24 15:18:52 2017 Antoine Briaux
** Last update Tue Jun  6 16:55:15 2017 Antoine Briaux
*/

#ifndef __VIEW__
# define __VIEW__

# include <SFML/Graphics.h>
# include "maze.h"

# define SCENE_NAME	"dante"
# define SCENE_WIDTH	1000
# define SCENE_HEIGHT	1000
# define SCENE_BPP 		32
# define SIZE 10

typedef struct 		s_framebuffer
{
	sfUint8 		*pixels;
	int 			width;
	int 			height;
}					t_framebuffer;

typedef struct 		s_view
{
	sfVideoMode		mode;
	sfRenderWindow	*window;
	sfTexture 		*texture;
	sfSprite		*sprite;
	t_framebuffer	framebuf;
}					t_view;

void 		init_view(t_view *view);
void 	draw_square(t_view *view, int posx, int posy, sfColor color);
void 	update_render(t_view *view, t_maze *map);
void 	destroy_view(t_view *view);

void 	breadth_search(t_maze *maze, int x, t_view *view);

#endif /* ! __VIEW__ */
