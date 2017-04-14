#include <libft.h>
#include <libxft.h>
#include <stdlib.h>
#include <limits.h>

#include "wolf.h"

#include "key_esc.h"
#include "key_up.h"
#include "key_down.h"
#include "key_left.h"
#include "key_right.h"

static void		s_list_key_func(t_ptr_key_func *f)
{
	f[X_ESC_KEY] = &key_esc;
	f[X_UP_KEY] = &key_up;
	f[X_DOWN_KEY] = &key_down;
	f[X_LEFT_KEY] = &key_left;
	f[X_RIGHT_KEY] = &key_right;
}

static void		s_ini_key_func(t_ptr_key_func **af)
{
	t_ptr_key_func	*f;
	int				i;

	if ((*af = malloc(sizeof(t_ptr_key_func*) * 0xFFFF)) == NULL)
		return ;
	f = *af;
	i = 0;
	while (i < 0xFFFF)
		f[i++] = NULL;
	s_list_key_func(f);
}

void			key_func(int key, t_display *d, int e)
{
	static t_ptr_key_func	*f = NULL;

	if (f == NULL)
		s_ini_key_func(&f);
	if (f != NULL && key < 0xFFFF && f[key] != NULL)
		f[key](d, e);
}
