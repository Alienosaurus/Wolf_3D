#include "libft.h"

t_listd	*ft_lstd_front(t_listd *lstd)
{
	if (lstd && lstd->prev)
		return (ft_lstd_front(lstd->prev));
	return (lstd);
}
