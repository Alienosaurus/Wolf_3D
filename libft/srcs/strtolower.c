#include <stdlib.h>
#include "libft.h"

char	*ft_strtolower(char *s)
{
	int		i;
	int		len;
	char	*ret;

	len = ft_strlen(s);
	if ((ret = malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = ft_tolower(s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
