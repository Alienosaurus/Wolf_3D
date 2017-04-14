#ifndef LIBXFT_H
# define LIBXFT_H

# include <unistd.h>

# define X_ESC_KEY				0X35
# define X_1_KEY				0X12
# define X_2_KEY				0X13
# define X_3_KEY				0X14
# define X_4_KEY				0X15
# define X_5_KEY				0X17
# define X_6_KEY				0X16
# define X_7_KEY				0X1A
# define X_8_KEY				0X1C
# define X_9_KEY				0X19
# define X_TAB_KEY				0X30
# define X_UP_KEY				0X7E
# define X_DOWN_KEY				0X7D
# define X_LEFT_KEY				0X7B
# define X_RIGHT_KEY				0X7C
# define X_Q_KEY				0XC
# define X_W_KEY				0XD
# define X_E_KEY				0XE
# define X_R_KEY				0XF
# define X_T_KEY				0X11
# define X_Y_KEY				0X10
# define X_U_KEY				0X20
# define X_I_KEY				0X22
# define X_O_KEY				0X1F
# define X_P_KEY				0X23
# define X_BRACKET_OPEN_KEY			0X21
# define X_BRACKET_CLOSE_KEY			0X1E
# define X_PIPE_KEY				0X2A
# define X_A_KEY				0X0
# define X_S_KEY				0X1
# define X_D_KEY				0X2
# define X_F_KEY				0X3
# define X_G_KEY				0X5
# define X_H_KEY				0X4
# define X_J_KEY				0X26
# define X_K_KEY				0X28
# define X_L_KEY				0X25
# define X_DOUBLE_DOTS_KEY			0X29
# define X_QUOTE_KEY				0X27
# define X_Z_KEY				0X6
# define X_X_KEY				0X7
# define X_C_KEY				0X8
# define X_V_KEY				0X9
# define X_B_KEY				0XB
# define X_N_KEY				0X2D
# define X_M_KEY				0X2E
# define X_INFERIOR_KEY				0X2B
# define X_SUPERIOR_KEY				0X2F
# define X_QUESTION_MARK_KEY			0X2C

typedef struct	s_vector
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
}		t_vector;

typedef struct	s_image
{
	void	*img_ptr;
	int	width;
	int	height;
	char	*data_addr;
	int	bits_per_pixel;
	int	size_line;
	int	endian;
}		t_image;

t_image			*ft_mlx_new_image(void *mlx, int width, int height);
t_image			*ft_mlx_xpm_file_to_image(void *mlx, char *path_file);
int			ft_mlx_get_color_in_image(t_image *img, int x, int y);
void			ft_mlx_put_pixel_to_image(t_image *img,
		int x, int y, int color);
void			ft_mlx_image_to_image(t_image *img1, t_image *img2,
		int x, int y);

#endif
