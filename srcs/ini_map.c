#include <libft.h>
#include <stdlib.h>

#include "wolf.h"
#include "sgt_map.h"

int		ini_map(t_display *d)
{
	if ((d->map = malloc(sizeof(t_map))) == NULL)
		return (-1);
	if ((d->map->map = sgt_map(0)) == NULL)
		return (-1);
	d->map->width = ft_strlen(d->map->map[0]);
	d->map->height = ft_strlistlen(d->map->map);
	return (0);
}
