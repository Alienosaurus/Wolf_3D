#include <stdlib.h>

#include "wolf.h"

int		ini_key(t_display *d)
{
	if ((d->keys = malloc(sizeof(t_key))) == NULL)
		return (-1);
	d->keys->up = 0;
	d->keys->down = 0;
	d->keys->left = 0;
	d->keys->right = 0;
	return (0);
}
