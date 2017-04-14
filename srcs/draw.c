#include <libxft.h>

#include "draw_color.h"
#include "draw_tex.h"
#include "wolf.h"

void	draw(t_display *d, int x, int color)
{
	if (d->map->map[d->ray->map_y][d->ray->map_x] == '1')
		draw_color(d, x, color);
	else
		draw_tex(d, x);
}
