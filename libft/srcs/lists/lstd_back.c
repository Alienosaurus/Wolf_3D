#include "libft.h"

t_listd		*ft_lstd_back(t_listd *lstd)
{
	if (lstd && lstd->next)
		return (ft_lstd_back(lstd->next));
	return (lstd);
}
