#include "libft.h"

size_t	ft_lstd_size(t_listd *lstd)
{
	size_t		count;
	t_listd		*front;

	count = 0;
	front = ft_lstd_front(lstd);
	while (front)
	{
		++count;
		front = front->next;
	}
	return (count);
}
