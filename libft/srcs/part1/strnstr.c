#include <unistd.h>
#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	t;
	size_t	ptr;

	i = 0;
	j = 0;
	t = 0;
	ptr = 0;
	while (s1[i] != '\0' && i < n)
	{
		if (s2[j] == s1[i])
		{
			if (j++ == 0)
				ptr = i;
		}
		else if (!(j = 0))
			i = t++;
		i++;
		if (s2[j] == '\0')
			return ((char *)(s1 + ptr));
	}
	return (NULL);
}
