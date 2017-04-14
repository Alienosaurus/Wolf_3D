#include <unistd.h>

size_t	ft_strlistlen(char **l)
{
	size_t	i;

	i = 0;
	if (l)
	{
		while (l[i])
			i++;
	}
	return (i);
}
