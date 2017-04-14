#include <libxft.h>

#include "wolf.h"

int		ini_xpm(t_display *d)
{
	if ((d->img_xpm[0] = ft_mlx_xpm_file_to_image(d->mlx, PATH_TEX_1)) == NULL)
		return (-1);
	if ((d->img_xpm[1] = ft_mlx_xpm_file_to_image(d->mlx, PATH_TEX_2)) == NULL)
		return (-1);
	if ((d->img_xpm[2] = ft_mlx_xpm_file_to_image(d->mlx, PATH_TEX_3)) == NULL)
		return (-1);
	if ((d->img_xpm[3] = ft_mlx_xpm_file_to_image(d->mlx, PATH_TEX_4)) == NULL)
		return (-1);
	if ((d->img_sky = ft_mlx_xpm_file_to_image(d->mlx, PATH_TEX_SKY)) == NULL)
		return (-1);
	return (0);
}
