#include "libft.h"

static size_t	ft_lenofnbr(int n)
{
	size_t	i;

	i = 2;
	if (n == -2147483648)
		return (12);
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static void		ft_straddchar(char *s1, char c)
{
	s1[0] = c;
	s1[1] = '\0';
}

static void		ft_strcal(char *str, int n)
{
	if (n < 0)
	{
		ft_straddchar(ft_strchr(str, '\0'), '-');
		n = n * -1;
	}
	if (n < 10)
		ft_straddchar(ft_strchr(str, '\0'), '0' + n);
	else
	{
		ft_strcal(str, n / 10);
		ft_straddchar(ft_strchr(str, '\0'), '0' + n % 10);
	}
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	len = ft_lenofnbr(n);
	str = ft_strnew(len);
	if (str)
	{
		if (n == -2147483648)
			return (ft_strcat(str, "-2147483648"));
		ft_strcal(str, n);
	}
	return (str);
}
