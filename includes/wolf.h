#ifndef WOLF_H
# define WOLF_H

# include <libxft.h>

# define USAGE			"usage: wolf3d [map file]"

# define PATH_TEX_1		"./xpm/t1.xpm"
# define PATH_TEX_2		"./xpm/t2.xpm"
# define PATH_TEX_3		"./xpm/t3.xpm"
# define PATH_TEX_4		"./xpm/t4.xpm"
# define PATH_TEX_SKY		"./xpm/sky.xpm"

# define WIN_WIDTH		800
# define WIN_HEIGHT		600

# define ROT_SPEED		0.05
# define MOVE_SPEED		0.1

typedef struct		s_key
{
	int		up;
	int		down;
	int		left;
	int		right;
}			t_key;

typedef struct		s_player
{
	double		x;
	double		y;
	double		rot;
	double		cam_x;
	double		cam_y;
	double		plane_x;
	double		plane_y;
}			t_player;

typedef struct		s_map
{
	char		**map;
	int		width;
	int		height;
}			t_map;

typedef struct		s_raycaster
{
	double		cam_x;
	double		ray_pos_x;
	double		ray_pos_y;
	double		ray_cam_x;
	double		ray_cam_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_dist;
	double		line_height;
	int		map_x;
	int		map_y;
	int		draw_start;
	int		draw_end;
}			t_raycaster;

typedef struct		s_display
{
	void		*mlx;
	void		*win;
	t_image		*img;
	t_map		*map;
	t_raycaster	*ray;
	t_player	*player;
	t_key		*keys;
	t_image		*img_sky;
	t_image		*img_xpm[4];
}			t_display;

typedef void		(*t_ptr_key_func)(t_display*, int);

int			ini_display(t_display *d);
void			ft_wolf(void);

#endif
