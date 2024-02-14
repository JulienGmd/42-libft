/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:47:44 by jgrimaud          #+#    #+#             */
/*   Updated: 2024/02/14 06:04:35 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// TODO attention aux fonctions qu'on call ici car elles peuvent call ft_malloc
// ou ft_free
// i.e. infinite loop

/**
 * Check if a pointer is NULL. Exit the program if it is.
 */
void	*check_ptr(void *ptr, t_list **ptr_list)
{
	expect(ptr != NULL, "check_ptr: ptr is NULL", ptr_list);
	return (ptr);
}

/**
 * Allocate size bytes. Exit the program if it fails.
*/
void	*ft_malloc(size_t size, t_list **ptr_list)
{
	void	*ptr;

	expect(size != 0, "ft_malloc: size is 0", ptr_list);
	ptr = check_ptr(malloc(size), ptr_list);
	add_to_ptr_list(ptr, ptr_list);
	return (ptr);
}

/**
 * Allocate nmemb * size bytes and set them to 0. Exit the program if it fails.
 */
void	*ft_calloc(size_t nmemb, size_t size, t_list **ptr_list)
{
	void	*ptr;

	expect(size != 0, "ft_calloc: size is 0", ptr_list);
	expect(nmemb != 0, "ft_calloc: nmemb is 0", ptr_list);
	expect(size <= SIZE_MAX / nmemb, "ft_calloc: size_t overflow", ptr_list);
	ptr = ft_malloc(nmemb * size, ptr_list);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/**
 * Reallocate ptr to size bytes. If ptr is NULL, it's the same as malloc(size).
 * If size is 0, it's the same as free(ptr). Exit the program if it fails.
 */
void	*ft_realloc(void *ptr, size_t size, size_t old_size, t_list **ptr_list)
{
	char	*new_ptr;

	new_ptr = NULL;
	if (size > 0)
	{
		new_ptr = ft_malloc(size, ptr_list);
		if (ptr)
			ft_memmove(new_ptr, ptr, ft_min(size, old_size));
	}
	ft_free(&ptr, ptr_list);
	return (new_ptr);
}

/**
 * Free a pointer and set it to NULL.
*/
void	ft_free(void **ptr, t_list **ptr_list)
{
	if (ptr && *ptr)
	{
		ft_lstdelshift(ptr_list, *ptr, free);
		*ptr = NULL;
	}
}
