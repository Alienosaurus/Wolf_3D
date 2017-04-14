#include "libft.h"
#include <stdlib.h>

void	ft_lstd_del(t_listd **alst, void (*del)(void*))
{
	t_listd		*next;
	t_listd		*prev;

	if (!alst || !*alst)
		return ;
	next = (*alst)->next;
	prev = (*alst)->prev;
	if ((*alst)->data)
		del((*alst)->data);
	if (next)
		next->prev = prev;
	if (prev)
		prev->next = next;
	free(*alst);
}
