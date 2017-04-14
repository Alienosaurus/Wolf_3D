#include <stdlib.h>
#include "libft.h"

void	ft_lstd_push_after(t_listd **alst, void *new)
{
	t_listd		*after;
	t_listd		*tmp;

	if (!alst || !*alst)
	{
		ft_lstd_new(alst, new);
		return ;
	}
	if ((tmp = malloc(sizeof(t_listd))) != NULL)
	{
		after = (*alst)->next;
		tmp->data = new;
		tmp->prev = *alst;
		tmp->next = after;
		(*alst)->next = tmp;
	}
}
