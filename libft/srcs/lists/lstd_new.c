#include <stdlib.h>
#include "libft.h"

void	ft_lstd_new(t_listd **alst, void *new)
{
	t_listd		*tmp;

	if ((tmp = malloc(sizeof(t_listd))) != NULL)
	{
		tmp->data = new;
		tmp->prev = NULL;
		tmp->next = NULL;
		*alst = tmp;
	}
}
