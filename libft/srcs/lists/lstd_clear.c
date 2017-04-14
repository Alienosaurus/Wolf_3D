#include "libft.h"
#include <stdlib.h>

void	ft_lstd_clear(t_listd **alst, void (*del)(void*))
{
	t_listd		*tmp;

	if (!alst || !*alst)
		return ;
	while (*alst)
	{
		del((*alst)->data);
		tmp = *alst;
		*alst = (*alst)->next;
		free(tmp);
	}
}
