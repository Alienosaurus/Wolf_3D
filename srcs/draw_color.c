#include <libxft.h>

#include "wolf.h"

void	draw_color(t_display *d, int x, int color)
{
	int		i;

	i = d->ray->draw_start;
	while (i < d->ray->draw_end)
	{
		ft_mlx_put_pixel_to_image(d->img, x, i, color);
		i++;
	}
}
