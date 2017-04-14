#include "libft.h"

void	ft_putendlcolor(char *s, char type, char state, int color)
{
	char	*tmp;

	tmp = ft_strcolor(s, type, state, color);
	ft_putendl(tmp);
	ft_strdel(&tmp);
}
