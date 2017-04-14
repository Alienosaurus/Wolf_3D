#include "libft.h"

int		ft_isnumber(char *s)
{
	int		i;

	i = 0;
	if (s && *s && (*s == '-' || (*s >= '0' && *s <= '9')))
	{
		if ((*s >= '0' && *s <= '9'))
			i = 1;
		++s;
		while (s && *s && *s >= '0' && *s <= '9')
		{
			i = (i == 0) ? 1 : 0;
			++s;
		}
		if (*s)
			return (0);
		else if (i == 1)
			return (1);
	}
	return (0);
}
