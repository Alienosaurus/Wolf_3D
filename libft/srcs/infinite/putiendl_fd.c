#include "libft.h"
#include <stdarg.h>
#include <string.h>

void		ft_putiendl_fd(int fd, char *s, ...)
{
	va_list		args;
	char		*str;
	char		*tmp;
	int			len;

	len = 0;
	len += ft_strlen(s);
	va_start(args, s);
	while ((str = (char *)va_arg(args, char *)))
		len += ft_strlen(str);
	va_end(args);
	str = ft_strnew(len + 2);
	str = ft_strcat(str, s);
	va_start(args, s);
	while ((tmp = (char *)va_arg(args, char *)))
		str = ft_strcat(str, tmp);
	va_end(args);
	str[len] = '\n';
	ft_putstr_fd(str, fd);
	ft_strdel(&str);
}