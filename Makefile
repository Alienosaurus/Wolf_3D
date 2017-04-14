NAME		=	wolf3d

NAMEBASE    =   $(shell basename $(NAME))

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -ggdb -O3

SRCDIR		=	srcs/

OBJDIR		=	objs/

INCDIR		=	includes/

MLX_DIR		=	minilibx_macos/
MLX_FLAGS_O	=	-L ./$(MLX_DIR) -framework OPENGL -framework AppKit -lmlx -O3
MLX_FLAGS_C	=	-L ./$(MLX_DIR) -framework OPENGL -framework AppKit -lmlx -O3

LIBFT_DIR	=	libft/

LIBFT_LIB	=	libft/libft.a

LIBXFT_DIR	=	libxft/

LIBXFT_LIB	=	libxft/libxft.a

SRCBASE		=	\
				color.c														\
				draw.c														\
				draw_bg.c													\
				draw_color.c												\
				draw_tex.c													\
				expose.c													\
				hook.c														\
				ini_key.c													\
				ini_map.c													\
				ini_player.c												\
				ini_ray.c													\
				ini_xpm.c													\
				key_func.c													\
				keys/key_down.c												\
				keys/key_esc.c												\
				keys/key_left.c												\
				keys/key_right.c											\
				keys/key_up.c												\
				main.c														\
				move.c														\
				open_map.c													\
				raytracer.c													\
				sgt_bin_name.c												\
				sgt_cos_sin_rot.c											\
				sgt_map.c													\
				wolf.c

INCBASE		=	\
				color.h														\
				draw.h														\
				draw_bg.h													\
				draw_color.h												\
				draw_tex.h													\
				expose.h													\
				hook.h														\
				ini_key.h													\
				ini_map.h													\
				ini_player.h												\
				ini_ray.h													\
				ini_xpm.h													\
				key_down.h													\
				key_esc.h													\
				key_func.h													\
				key_left.h													\
				key_right.h													\
				key_up.h													\
				libft.h														\
				libxft.h													\
				move.h														\
				open_map.h													\
				raytracer.h													\
				sgt_bin_name.h												\
				sgt_cos_sin_rot.h											\
				sgt_map.h													\
				wolf.h

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))

INCS		=	$(addprefix $(INCDIR), $(INCBASE))

OBJS		=	$(addprefix $(OBJDIR), $(shell basename $(SRCBASE:.c=.o)))

.SILENT:

all:		$(NAME)
	echo "\033[38;5;44m☑️  ALL    $(NAMEBASE) is done\033[0m\033[K"

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) $(MLX_FLAGS_O) -o $(NAME) $(OBJS)						\
		$(LIBFT_LIB) $(LIBXFT_LIB)
	echo -en "\r\033[38;5;22m📗  MAKE   $(NAMEBASE)\033[0m\033[K"
	echo "\r\033[38;5;184m👥  GROUP MEMBER(S):\033[0m\033[K"
	echo "\r\033[38;5;15m`cat auteur | sed s/^/\ \ \ \ -/g`\033[0m\033[K"

$(OBJS):	$(SRCS) $(INCS)
	mkdir -p $(OBJDIR)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	make -C $(LIBXFT_DIR)
	printf "\r\033[38;5;11m⌛  MAKE   $(NAMEBASE) plz wait ...\033[0m\033[K"
	(cd $(OBJDIR) &&														\
	$(CC) $(FLAGS) -c $(addprefix ../, $(SRCS))				\
	-I $(addprefix ../, $(LIBFT_DIR)/$(INCDIR))								\
	-I $(addprefix ../, $(LIBXFT_DIR)/$(INCDIR))							\
	-I $(addprefix ../, $(INCDIR)))

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAMEBASE) plz wait ...\033[0m\033[K"
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean
	make -C $(LIBXFT_DIR) clean
	if [[ `rm -R $(OBJDIR) &> /dev/null 2>&1; echo $$?` == "0" ]]; then		\
		echo -en "\r\033[38;5;124m📕  CLEAN  $(NAMEBASE)\033[0m\033[K";		\
	else																	\
		printf "\r";														\
	fi

fclean:		clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAMEBASE) Please wait ...\033[0m\033[K"
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBXFT_DIR) fclean
	if [[ `rm $(NAME) &> /dev/null 2>&1; echo $$?` == "0" ]]; then			\
		echo -en "\r\033[38;5;124m📕  FCLEAN $(NAMEBASE)\033[0m\033[K";		\
	else																	\
		printf "\r";														\
	fi

re:			fclean all

debug:		CC = cc
debug:		FLAGS += --analyze
debug:		re

.PHONY:		fclean clean re
