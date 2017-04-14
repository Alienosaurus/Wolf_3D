NAME		=	libft

NAMEBASE    =   $(shell basename $(NAME))

CC			=	gcc

FLAG		=	-Wall -Wextra -Werror

SRCDIR		=	srcs/

OBJDIR		=	objs/

INCDIR		=	includes/

SRCBASE		=	\
				bonus/lstadd.c												\
				bonus/lstdel.c												\
				bonus/lstdelone.c											\
				bonus/lstiter.c												\
				bonus/lstmap.c												\
				bonus/lstnew.c												\
				color/putendlcolor.c										\
				color/putstrcolor.c											\
				color/strcolor.c											\
				color/strcolord.c											\
				get_next_line.c												\
				infinite/error.c											\
				infinite/putiendl.c											\
				infinite/putiendl_fd.c										\
				infinite/putistr.c											\
				infinite/putistr_fd.c										\
				infinite/stridel.c											\
				infinite/strijoin.c											\
				infinite/strijoind.c										\
				lists/lstd_back.c											\
				lists/lstd_clear.c											\
				lists/lstd_del.c											\
				lists/lstd_front.c											\
				lists/lstd_get_last.c										\
				lists/lstd_new.c											\
				lists/lstd_pop_back.c										\
				lists/lstd_pop_front.c										\
				lists/lstd_push_after.c										\
				lists/lstd_push_back.c										\
				lists/lstd_push_before.c									\
				lists/lstd_push_cond.c										\
				lists/lstd_push_front.c										\
				lists/lstd_size.c											\
				part1/atoi.c												\
				part1/bzero.c												\
				part1/isalnum.c												\
				part1/isalpha.c												\
				part1/isascii.c												\
				part1/isdigit.c												\
				part1/isprint.c												\
				part1/memccpy.c												\
				part1/memchr.c												\
				part1/memcmp.c												\
				part1/memcpy.c												\
				part1/memmove.c												\
				part1/memset.c												\
				part1/strcat.c												\
				part1/strchr.c												\
				part1/strcmp.c												\
				part1/strcpy.c												\
				part1/strdup.c												\
				part1/strlcat.c												\
				part1/strlen.c												\
				part1/strncat.c												\
				part1/strncmp.c												\
				part1/strncpy.c												\
				part1/strnstr.c												\
				part1/strrchr.c												\
				part1/strstr.c												\
				part1/tolower.c												\
				part1/toupper.c												\
				part2/itoa.c												\
				part2/memalloc.c											\
				part2/memdel.c												\
				part2/putchar.c												\
				part2/putchar_fd.c											\
				part2/putendl.c												\
				part2/putendl_fd.c											\
				part2/putnbr.c												\
				part2/putnbr_fd.c											\
				part2/putstr.c												\
				part2/putstr_fd.c											\
				part2/strclr.c												\
				part2/strdel.c												\
				part2/strequ.c												\
				part2/striter.c												\
				part2/striteri.c											\
				part2/strjoin.c												\
				part2/strmap.c												\
				part2/strmapi.c												\
				part2/strnequ.c												\
				part2/strnew.c												\
				part2/strsplit.c											\
				part2/strsub.c												\
				part2/strtrim.c												\
				string/isnumber.c											\
				strtolower.c												\
				table/strlistdel.c											\
				table/strlistlen.c

INCBASE		= \
				libft.h

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))

INCS		=	$(addprefix $(INCDIR), $(INCBASE))

OBJS		=	$(addprefix $(OBJDIR), $(shell basename $(SRCBASE:.c=.o)))

.SILENT:

all:		$(NAME)

$(NAME):	$(OBJS)

$(OBJS):	$(SRCS) $(INCS)
	printf "\r\033[38;5;11m⌛  MAKE   $(NAME) Please stand by ...\033[0m\033[K"
	mkdir -p $(OBJDIR)
	(cd $(OBJDIR);															\
	$(CC) $(FLAGS) -c $(addprefix ../, $(SRCS))								\
	-I $(addprefix ../, $(INCDIR)))
	ar rc $(NAME).a $(OBJS)
	ranlib $(NAME).a
	echo -en "\r\033[38;5;25m📘  MAKE   $(NAME)\033[0m\033[K"

clean:
	if [[ `rm -R $(OBJDIR) &> /dev/null 2>&1; echo $$?` == "0" ]]; then		\
		echo -en "\r\033[38;5;124m📕  CLEAN  $(NAME)\033[0m\033[K";			\
	else																	\
		printf "\r";														\
	fi

fclean:		clean
	if [[ `rm $(NAME).a &> /dev/null 2>&1; echo $$?` == "0" ]]; then		\
		echo -en "\r\033[38;5;124m📕  FCLEAN $(NAME)\033[0m\033[K";			\
	else																	\
		printf "\r";														\
	fi

re:			fclean all

.PHONY:		fclean clean re
