#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char	*tmp;
	int		len;

	if (!s)
		write(fd, "\n", 1);
	len = ft_strlen(s);
	tmp = ft_strnew(len + 2);
	tmp = ft_memcpy(tmp, s, len + 1);
	tmp[len] = '\n';
	write(fd, tmp, len + 1);
	ft_strdel(&tmp);
}
