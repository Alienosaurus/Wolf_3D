#include <stdlib.h>

#include "wolf.h"

static int	s_set_place_player(t_display *d)
{
	int		x;
	int		y;

	y = 1;
	while (d->map && d->map->map[y] != NULL)
	{
		x = 1;
		while (d->map->map[y][x] != '\0')
		{
			if (d->map->map[y][x] == '0')
			{
				d->player->x = y + 0.01;
				d->player->y = x + 0.01;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

int			ini_player(t_display *d)
{
	if ((d->player = malloc(sizeof(t_player))) == NULL)
		return (-1);
	if (s_set_place_player(d) == -1)
		return (-1);
	d->player->rot = 0;
	d->player->cam_x = 0;
	d->player->cam_y = 1;
	d->player->plane_x = 0.66;
	d->player->plane_y = 0;
	return (0);
}
