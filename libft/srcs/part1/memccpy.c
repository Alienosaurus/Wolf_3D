#include <unistd.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*cpys1;
	const char	*cpys2;
	char		ch;

	cpys1 = s1;
	cpys2 = s2;
	while (n--)
	{
		ch = *cpys2++;
		*cpys1++ = ch;
		if (ch == (char)c)
			return (cpys1);
	}
	return (NULL);
}
