#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (size == 0)
		return (NULL);
	if ((mem = (void *)malloc(size)) == NULL)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
