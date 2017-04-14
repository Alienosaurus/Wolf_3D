#include <libxft.h>

#include "draw_bg.h"

static void		s_draw_bg(t_display *d)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	i = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			if (y > WIN_HEIGHT / 2)
			{
				if (i == 0)
					ft_mlx_put_pixel_to_image(d->img, x, y, 0x727272);
				else
					ft_mlx_put_pixel_to_image(d->img, x, y, 0x121212);
			}
			++y;
			i = (x + y) % 5;
		}
		++x;
	}
}

void			draw_bg(t_display *d)
{
	if (d->player->cam_y > 0)
	{
		if (d->player->cam_x > 0)
			d->player->rot = (d->player->cam_x - d->player->cam_y)
				* 400 + 800;
		else
			d->player->rot = (d->player->cam_x + d->player->cam_y)
				* 400 + 1600;
	}
	else
	{
		if (d->player->cam_x > 0)
			d->player->rot = -(d->player->cam_x + d->player->cam_y)
				* 400 + 1600;
		else
			d->player->rot = -(d->player->cam_x - d->player->cam_y)
				* 400 + 800;
	}
	ft_mlx_image_to_image(d->img, d->img_sky,
			-d->player->rot, 0);
	ft_mlx_image_to_image(d->img, d->img_sky,
			-d->player->rot + 1600, 0);
	ft_mlx_image_to_image(d->img, d->img_sky,
			-d->player->rot + 3200, 0);
	s_draw_bg(d);
}
