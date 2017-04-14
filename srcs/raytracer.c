#include <libft.h>
#include <math.h>
#include <stdlib.h>

#include <stdio.h>

#include "wolf.h"
#include "color.h"
#include "draw_bg.h"
#include "draw.h"

static void		s_ray1(int x, t_display *d)
{
	d->ray->cam_x = 2 * x / (double)WIN_WIDTH - 1;
	d->ray->ray_pos_x = d->player->y;
	d->ray->ray_pos_y = d->player->x;
	d->ray->ray_cam_x = d->player->cam_x + d->player->plane_x * d->ray->cam_x;
	d->ray->ray_cam_y = d->player->cam_y + d->player->plane_y * d->ray->cam_x;
	d->ray->map_x = (int)d->player->y;
	d->ray->map_y = (int)d->player->x;
	d->ray->delta_dist_x = sqrt(1 + pow(d->ray->ray_cam_y, 2)
		/ pow(d->ray->ray_cam_x, 2));
	d->ray->delta_dist_y = sqrt(1 + pow(d->ray->ray_cam_x, 2)
		/ pow(d->ray->ray_cam_y, 2));
}

static void		s_ray2(t_display *d)
{
	d->ray->hit = 0;
	if (d->ray->ray_cam_x < 0)
	{
		d->ray->step_x = -1;
		d->ray->side_dist_x = (d->ray->ray_pos_x - d->ray->map_x)
			* d->ray->delta_dist_x;
	}
	else
	{
		d->ray->step_x = 1;
		d->ray->side_dist_x = (d->ray->map_x + 1.0 - d->ray->ray_pos_x)
			* d->ray->delta_dist_x;
	}
	if (d->ray->ray_cam_y < 0)
	{
		d->ray->step_y = -1;
		d->ray->side_dist_y = (d->ray->ray_pos_y - d->ray->map_y)
			* d->ray->delta_dist_y;
	}
	else
	{
		d->ray->step_y = 1;
		d->ray->side_dist_y = (d->ray->map_y + 1.0 - d->ray->ray_pos_y)
			* d->ray->delta_dist_y;
	}
}

static void		s_ray3(t_display *d)
{
	d->ray->side = 0;
	while (d->ray->hit == 0)
	{
		if (d->ray->side_dist_x < d->ray->side_dist_y)
		{
			d->ray->side_dist_x += d->ray->delta_dist_x;
			d->ray->map_x += d->ray->step_x;
			d->ray->side = 0;
		}
		else
		{
			d->ray->side_dist_y += d->ray->delta_dist_y;
			d->ray->map_y += d->ray->step_y;
			d->ray->side = 1;
		}
		if (d->ray->map_x < d->map->width && d->ray->map_y < d->map->height
			&& d->map->map[d->ray->map_y][d->ray->map_x] != '0')
			d->ray->hit = 1;
	}
}

static void		s_ray4(t_display *d)
{
	double	p1;
	double	p2;

	p1 = fabs((d->ray->map_x - d->ray->ray_pos_x + (1 - d->ray->step_x) / 2)
		/ d->ray->ray_cam_x);
	p2 = fabs((d->ray->map_y - d->ray->ray_pos_y + (1 - d->ray->step_y) / 2)
		/ d->ray->ray_cam_y);
	if (d->ray->side == 0)
		d->ray->perp_wall_dist = p1;
	else
		d->ray->perp_wall_dist = p2;
	d->ray->line_height = abs((int)(WIN_HEIGHT / d->ray->perp_wall_dist));
	d->ray->draw_start = -d->ray->line_height / 2 + WIN_HEIGHT / 2;
	if (d->ray->draw_start < 0)
		d->ray->draw_start = 0;
	d->ray->draw_end = d->ray->line_height / 2 + WIN_HEIGHT / 2;
	if (d->ray->draw_end >= WIN_HEIGHT)
		d->ray->draw_end = WIN_HEIGHT - 1;
}

void			raycastring(t_display *d)
{
	int		x;

	x = 0;
	draw_bg(d);
	while (x < WIN_WIDTH)
	{
		s_ray1(x, d);
		s_ray2(d);
		s_ray3(d);
		s_ray4(d);
		draw(d, x, color(d));
		x++;
	}
}
