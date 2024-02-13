/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 22:19:49 by jgrimaud          #+#    #+#             */
/*   Updated: 2024/02/13 22:19:58 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Add the pointer to the list, creating the list if it does not exist.
*/
void	add_to_ptr_list(void *ptr, t_list **ptr_list)
{
	t_list	*node;

	expect(ptr != NULL, "add_to_ptr_list: ptr is NULL", ptr_list);
	node = ft_lstnew(ptr);
	if (!node)
	{
		free(ptr);
		clean_exit_with_error("add_to_ptr_list: malloc failed", ptr_list);
	}
	ft_lstadd_back(ptr_list, node);
}

/**
 * Free all the pointers in the list and the list itself.
*/
void	cleanup(t_list **ptr_list)
{
	ft_lstclear(ptr_list, free);
}
