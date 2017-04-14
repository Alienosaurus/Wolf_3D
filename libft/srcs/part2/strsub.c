#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	size_t	j;

	str = "";
	if (s == NULL || len <= 0)
		return (str);
	i = start;
	j = 0;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str)
	{
		while (s[i] && j < len)
		{
			str[j] = s[i];
			i++;
			j++;
		}
		str[j] = '\0';
	}
	return (str);
}
