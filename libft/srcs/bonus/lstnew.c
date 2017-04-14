#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	if ((tmp = malloc(sizeof(t_list))) != NULL)
	{
		if (!content)
		{
			tmp->content = NULL;
			tmp->content_size = 0;
		}
		else
		{
			tmp->content = (void *)content;
			tmp->content_size = content_size;
		}
		tmp->next = NULL;
	}
	return (tmp);
}
