#include <mlx.h>

#include "wolf.h"
#include "move.h"
#include "raytracer.h"

int		expose_loop_hook(t_display *d)
{
	move(d);
	raycastring(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img->img_ptr, 0, 0);
	return (1);
}
