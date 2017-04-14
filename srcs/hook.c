#include "wolf.h"
#include "key_func.h"

int		key_hook_press(int key, t_display *d)
{
	key_func(key, d, 1);
	return (1);
}

int		key_hook_release(int key, t_display *d)
{
	key_func(key, d, 0);
	return (1);
}
