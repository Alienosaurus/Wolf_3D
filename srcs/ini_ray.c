#include <stdlib.h>

#include "wolf.h"

int		ini_ray(t_display *d)
{
	if ((d->ray = malloc(sizeof(t_raycaster))) == NULL)
		return (-1);
	d->ray->map_x = 0;
	d->ray->map_y = 0;
	return (0);
}
