#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

void	ft_stridel(char **s, ...)
{
	va_list		args;
	char		**str;

	va_start(args, s);
	ft_strdel(s);
	while ((str = (char **)va_arg(args, char **)))
		ft_strdel(str);
	va_end(args);
}
