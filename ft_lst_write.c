/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:52:17 by jgrimaud          #+#    #+#             */
/*   Updated: 2024/03/16 03:14:47 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content, void *data)
{
	t_list	*lst;

	lst = ft_malloc(sizeof(t_list), data);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *), void *data)
{
	if (!lst || !del)
		return ;
	del(lst->content);
	ft_free((void **)&lst, data);
}

bool	ft_lstdelshift(t_list **lst, void *content, void (*del)(void *),
				void *data)
{
	t_list	*prev;
	t_list	*curr;

	prev = NULL;
	curr = *lst;
	while (curr)
	{
		if (curr->content == content)
		{
			if (prev)
				prev->next = curr->next;
			else
				*lst = curr->next;
			ft_lstdelone(curr, del, data);
			return (true);
		}
		prev = curr;
		curr = curr->next;
	}
	return (false);
}
