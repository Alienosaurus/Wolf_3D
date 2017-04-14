#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	ft_strlistdel(char **l)
{
	size_t	i;

	i = ft_strlistlen(l);
	while (i > 0)
	{
		free(l[i - 1]);
		i--;
	}
	free(l);
}
