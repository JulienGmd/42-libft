#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dup_first;
	t_list	*dup;

	if (!lst || !f)
		return (NULL);
	dup_first = malloc(sizeof(t_list));
	if (!dup_first)
		return (NULL);
	dup_first->content = f(lst->content);
	dup = dup_first;
	while (lst->next)
	{
		dup->next = malloc(sizeof(t_list));
		if (!dup->next)
			return (ft_lstclear(&dup_first, del), NULL);
		dup = dup->next;
		lst = lst->next;
		dup->content = f(lst->content);
	}
	dup->next = NULL;
	return (dup_first);
}
