#include <unistd.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)b;
	i = 0;
	while (i < len)
	{
		tmp[i] = c;
		i = i + 1;
	}
	b = tmp;
	return (b);
}
