#include <stdlib.h>
#include "libft.h"

void	ft_lstd_push_back(t_listd **alst, void *new)
{
	t_listd		*last;
	t_listd		*tmp;

	if (!alst || !*alst)
	{
		ft_lstd_new(alst, new);
		return ;
	}
	if ((tmp = malloc(sizeof(t_listd))) != NULL)
	{
		last = ft_lstd_back(*alst);
		tmp->data = new;
		tmp->prev = last;
		tmp->next = NULL;
		last->next = tmp;
	}
}
