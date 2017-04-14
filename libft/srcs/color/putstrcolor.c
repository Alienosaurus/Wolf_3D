#include "libft.h"

void	ft_putstrcolor(char *s, char type, char state, int color)
{
	char	*tmp;

	tmp = ft_strcolor(s, type, state, color);
	ft_putstr(tmp);
	ft_strdel(&tmp);
}
