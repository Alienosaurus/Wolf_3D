#include <libft.h>
#include <libxft.h>
#include <stdlib.h>
#include <mlx.h>

#include <stdio.h>

#include "wolf.h"
#include "hook.h"
#include "expose.h"
#include "sgt_map.h"
#include "ini_player.h"
#include "ini_xpm.h"
#include "ini_ray.h"
#include "ini_map.h"
#include "ini_key.h"

static int	ini_mlx(t_display *e)
{
	e->mlx = mlx_init();
	if (e->mlx == NULL)
		return (-1);
	e->win = mlx_new_window(e->mlx, WIN_WIDTH, WIN_HEIGHT, "Wolft3d");
	if (e->win == NULL)
		return (-1);
	e->img = ft_mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (e->img == NULL)
		return (-1);
	return (1);
}

int			ini_display(t_display *d)
{
	if (ini_map(d) == -1
		|| ini_ray(d) == -1
		|| ini_key(d) == -1
		|| ini_player(d) == -1
		|| ini_xpm(d) == -1)
		return (-1);
	return (0);
}

void		ft_wolf(void)
{
	t_display	*e;

	if ((e = malloc(sizeof(t_display))) == NULL)
		return (ft_error("ini_mlx", 0));
	if (ini_mlx(e) == -1)
		return (ft_error("ini_mlx", 0));
	if (ini_display(e) == -1)
		return (ft_error("ini_display", 0));
	mlx_do_key_autorepeatoff(e->mlx);
	mlx_hook(e->win, 2, (1L << 0), &key_hook_press, e);
	mlx_hook(e->win, 3, (1L << 1), &key_hook_release, e);
	mlx_loop_hook(e->mlx, &expose_loop_hook, e);
	mlx_loop(e->mlx);
}
