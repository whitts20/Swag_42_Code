#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *addend;
	
	addend = *lst;
	while (addend->content != NULL)
		addend->content = addend->next;
	addend->next = NULL;
	addend->content = new;
}
