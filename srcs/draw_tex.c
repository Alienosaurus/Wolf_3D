#include <libxft.h>
#include <math.h>

#include "wolf.h"

static t_image	*s_check_case(t_display *d)
{
	t_image		*t;

	t = d->img_xpm[0];
	if (d->map->map[d->ray->map_y][d->ray->map_x] == '2')
		t = d->img_xpm[1];
	if (d->map->map[d->ray->map_y][d->ray->map_x] == '3')
		t = d->img_xpm[2];
	if (d->map->map[d->ray->map_y][d->ray->map_x] == '4')
		t = d->img_xpm[3];
	return (t);
}

static int		s_get_tex_x(t_display *d, t_image *t, double wall_x)
{
	int		tex_x;

	tex_x = (int)(wall_x * t->width);
	if (d->ray->side == 0 && d->ray->ray_cam_x > 0)
		tex_x = t->width - tex_x - 1;
	if (d->ray->side == 1 && d->ray->ray_cam_y < 0)
		tex_x = t->width - tex_x - 1;
	return (tex_x);
}

static int		s_get_tex_y(t_display *d, t_image *t, int i)
{
	int		dc;
	int		tex_y;

	dc = i * 256 - WIN_HEIGHT * 128 + d->ray->line_height * 128;
	tex_y = ((dc * t->height) / d->ray->line_height) / 256;
	return (tex_y);
}

static double	s_get_wall_x(t_display *d)
{
	double	wall_x;

	if (d->ray->side == 1)
		wall_x = d->ray->ray_pos_x + ((d->ray->map_y
					- d->ray->ray_pos_y + (1 - d->ray->step_y) / 2)
			/ d->ray->ray_cam_y) * d->ray->ray_cam_x;
	else
		wall_x = d->ray->ray_pos_y + ((d->ray->map_x
					- d->ray->ray_pos_x + (1 - d->ray->step_x) / 2)
			/ d->ray->ray_cam_x) * d->ray->ray_cam_y;
	wall_x -= floor(wall_x);
	return (wall_x);
}

void			draw_tex(t_display *d, int x)
{
	int			i;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	t_image		*t;

	i = d->ray->draw_start;
	while (i < d->ray->draw_end)
	{
		t = s_check_case(d);
		wall_x = s_get_wall_x(d);
		tex_x = s_get_tex_x(d, t, wall_x);
		tex_y = s_get_tex_y(d, t, i);
		ft_mlx_put_pixel_to_image(d->img, x, i,
				ft_mlx_get_color_in_image(t, tex_x, tex_y));
		i++;
	}
}
