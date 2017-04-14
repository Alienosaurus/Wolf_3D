#include <stdlib.h>
#include "libft.h"

void	ft_lstd_pop_front(t_listd **alst, void (*del)(void*))
{
	t_listd		*front;

	if (!alst || !*alst)
		return ;
	front = ft_lstd_front(*alst);
	if (*alst == front)
		*alst = front->next;
	if (front->data)
		del(front->data);
	if (front->next)
		front->next->prev = NULL;
	free(front);
}
