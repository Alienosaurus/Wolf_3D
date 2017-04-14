#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	char	*tmp;

	if (!s)
		return (0);
	tmp = (char *)s;
	while (*tmp)
		++tmp;
	return (tmp - s);
}
