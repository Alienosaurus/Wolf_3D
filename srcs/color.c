#include <libft.h>

#include "wolf.h"

int		color(t_display *d)
{
	if (d->ray->side == 1 && d->ray->step_y == 1)
		return (0xFAAC58);
	else if (d->ray->side == 1)
		return (0x58FA82);
	else if (d->ray->side == 0 && d->ray->step_x == 1)
		return (0x4C0B5F);
	else if (d->ray->side == 0)
		return (0xD8D8D8);
	return (0xFFFFFF);
}
