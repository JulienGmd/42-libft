/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 22:19:49 by jgrimaud          #+#    #+#             */
/*   Updated: 2024/02/14 07:07:37 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Add the pointer to the list, creating the list if it does not exist.
 * @note Not calling ft_lstnew, because it calls ft_malloc, which calls
 * add_to_ptr_list (infinite loop).
*/
void	add_to_ptr_list(void *ptr, t_list **ptr_list)
{
	t_list	*node;

	expect(ptr != NULL, "add_to_ptr_list: ptr is NULL", ptr_list);
	node = malloc(sizeof(t_list));
	if (!node)
	{
		free(ptr);
		clean_exit_with_error("add_to_ptr_list: malloc failed", ptr_list);
	}
	node->content = ptr;
	node->next = NULL;
	ft_lstadd_back(ptr_list, node);
}

/**
 * Free a pointer and set it to NULL.
 * @note Not using ft_lstdelshift because it uses ft_free (infinite loop).
*/
void	ft_free(void **ptr, t_list **ptr_list)
{
	t_list	*curr;
	t_list	*prev;

	if (!ptr || !*ptr)
		return ;
	curr = *ptr_list;
	prev = NULL;
	while (curr)
	{
		if (curr->content == *ptr)
		{
			if (prev)
				prev->next = curr->next;
			else
				*ptr_list = curr->next;
			free(curr->content);
			free(curr);
			*ptr = NULL;
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

/**
 * Free all the pointers in the list and the list itself.
 * @note Not calling ft_lstclear to avoid infinite loop.
*/
void	cleanup(t_list **ptr_list)
{
	t_list	*curr;

	while (*ptr_list)
	{
		curr = *ptr_list;
		*ptr_list = curr->next;
		free(curr->content);
		free(curr);
	}
}
