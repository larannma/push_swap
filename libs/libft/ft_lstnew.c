#include "libft.h"

t_list	*ft_lstnew(void *content, int number)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->number = number;
	new->next = NULL;
	return (new);
}
