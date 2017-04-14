#include <stdlib.h>
#include "libft.h"

void	ft_lstd_pop_back(t_listd **alst, void (*del)(void*))
{
	t_listd		*back;

	if (!alst || !*alst)
		return ;
	back = ft_lstd_back(*alst);
	if (*alst == back)
		*alst = back->prev;
	if (back->data)
		del(back->data);
	if (back->prev)
		back->prev->next = NULL;
	free(back);
}
