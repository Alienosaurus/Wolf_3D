#include "libft.h"

t_listd		*ft_lstd_get_last(t_listd *alst)
{
	if (alst && alst->next)
		return (ft_lstd_get_last(alst->next));
	return (alst);
}
