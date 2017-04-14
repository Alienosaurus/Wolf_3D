#include <unistd.h>

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	char	*str;

	str = (char *)s1;
	while (*s1)
		s1++;
	while (n--)
	{
		if (!(*s1++ = *s2++))
			return (str);
	}
	*s1 = '\0';
	return (str);
}
