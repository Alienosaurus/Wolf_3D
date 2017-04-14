#include <stdlib.h>
#include "libft.h"

void	ft_lstd_push_before(t_listd **alst, void *new)
{
	t_listd		*tmp;

	if (!alst || !*alst)
	{
		ft_lstd_new(alst, new);
		return ;
	}
	if ((tmp = malloc(sizeof(t_listd))) != NULL)
	{
		tmp->data = new;
		tmp->prev = (*alst)->prev;
		tmp->next = *alst;
		if ((*alst)->prev)
		{
			(*alst)->prev->next = tmp;
			(*alst)->prev = tmp;
		}
		*alst = tmp;
	}
}
