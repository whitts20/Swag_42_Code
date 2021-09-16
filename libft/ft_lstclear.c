#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;

	if (del != NULL)
	{
		while (*lst != NULL && lst != NULL)
		{
			elem = (*lst)->next;
			ft_lstdelone(elem, del);
			lst = &elem;
		}
	}
}
