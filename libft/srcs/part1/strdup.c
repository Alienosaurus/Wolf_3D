#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*scpy;

	len = ft_strlen(s1) + 1;
	if ((scpy = (char *)malloc(len)) == NULL)
		return (NULL);
	ft_memcpy(scpy, s1, len);
	return (scpy);
}
