#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	tmp[n];

	ft_memcpy(tmp, s2, n);
	ft_memcpy(s1, tmp, n);
	return (s1);
}
