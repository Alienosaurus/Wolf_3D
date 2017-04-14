#include "wolf.h"
#include "sgt_cos_sin_rot.h"

static void		s_key_right(t_display *d)
{
	double	save_cam_x;
	double	save_plane_x;

	save_cam_x = d->player->cam_x;
	save_plane_x = d->player->plane_x;
	d->player->cam_x = d->player->cam_x * sgt_ncos_rot()
		- d->player->cam_y * sgt_nsin_rot();
	d->player->cam_y = save_cam_x * sgt_nsin_rot()
		+ d->player->cam_y * sgt_ncos_rot();
	d->player->plane_x = d->player->plane_x * sgt_ncos_rot()
		- d->player->plane_y * sgt_nsin_rot();
	d->player->plane_y = save_plane_x * sgt_nsin_rot()
		+ d->player->plane_y * sgt_ncos_rot();
}

static void		s_key_left(t_display *d)
{
	double	save_cam_x;
	double	save_plane_x;

	save_cam_x = d->player->cam_x;
	save_plane_x = d->player->plane_x;
	d->player->cam_x = d->player->cam_x * sgt_cos_rot()
		- d->player->cam_y * sgt_sin_rot();
	d->player->cam_y = save_cam_x * sgt_sin_rot()
		+ d->player->cam_y * sgt_cos_rot();
	d->player->plane_x = d->player->plane_x * sgt_cos_rot()
		- d->player->plane_y * sgt_sin_rot();
	d->player->plane_y = save_plane_x * sgt_sin_rot()
		+ d->player->plane_y * sgt_cos_rot();
}

static void		s_key_down(t_display *d)
{
	double	map_x;
	double	map_y;

	map_x = d->player->x - d->player->cam_y * MOVE_SPEED;
	map_y = d->player->y;
	if (d->map->map[(int)map_x][(int)map_y] == '0')
		d->player->x = map_x;
	map_x = d->player->x;
	map_y = d->player->y - d->player->cam_x * MOVE_SPEED;
	if (d->map->map[(int)map_x][(int)map_y] == '0')
		d->player->y = map_y;
}

static void		s_key_up(t_display *d)
{
	double	map_x;
	double	map_y;

	map_x = d->player->x + d->player->cam_y * MOVE_SPEED;
	map_y = d->player->y;
	if (d->map->map[(int)map_x][(int)map_y] == '0')
		d->player->x = map_x;
	map_x = d->player->x;
	map_y = d->player->y + d->player->cam_x * MOVE_SPEED;
	if (d->map->map[(int)map_x][(int)map_y] == '0')
		d->player->y = map_y;
}

void			move(t_display *d)
{
	if (d->keys->up)
		s_key_up(d);
	if (d->keys->down)
		s_key_down(d);
	if (d->keys->left)
		s_key_left(d);
	if (d->keys->right)
		s_key_right(d);
}
