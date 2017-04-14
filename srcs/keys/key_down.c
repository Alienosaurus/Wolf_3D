#include <stdlib.h>

#include "wolf.h"

void	key_down(t_display *d, int e)
{
	d->keys->down = e;
}
