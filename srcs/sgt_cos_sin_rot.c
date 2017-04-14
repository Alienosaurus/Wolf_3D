#include <math.h>

#include "wolf.h"

double	sgt_cos_rot(void)
{
	static double	t = 0;

	if (t == 0)
		t = cos(ROT_SPEED);
	return (t);
}

double	sgt_sin_rot(void)
{
	static double	t = 0;

	if (t == 0)
		t = sin(ROT_SPEED);
	return (t);
}

double	sgt_ncos_rot(void)
{
	static double	t = 0;

	if (t == 0)
		t = cos(-ROT_SPEED);
	return (t);
}

double	sgt_nsin_rot(void)
{
	static double	t = 0;

	if (t == 0)
		t = sin(-ROT_SPEED);
	return (t);
}
