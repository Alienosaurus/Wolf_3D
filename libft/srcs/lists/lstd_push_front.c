#include <stdlib.h>
#include "libft.h"

void	ft_lstd_push_front(t_listd **alst, void *new)
{
	t_listd		*front;
	t_listd		*tmp;

	if (!alst || !*alst)
		return (ft_lstd_new(alst, new));
	if ((tmp = malloc(sizeof(t_listd))) != NULL)
	{
		front = ft_lstd_front(*alst);
		tmp->data = new;
		tmp->prev = NULL;
		tmp->next = front;
		front->prev = tmp;
	}
}
