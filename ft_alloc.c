/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:47:44 by jgrimaud          #+#    #+#             */
/*   Updated: 2024/02/13 23:37:58 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// TODO attention aux fonctions qu'on call ici car elles peuvent call ft_malloc
// ou ft_free
// i.e. infinite loop

/**
 * If the pointer is NULL, exit the program.
 * @return The pointer if it is not NULL.
*/
void	*check_ptr(void *ptr, t_list **ptr_list)
{
	expect(ptr != NULL, "check_ptr: ptr is NULL", ptr_list);
	return (ptr);
}

/**
 * Allocate memory and exit the program if it fails.
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
 * Allocates memory for an array of nmemb elements of size bytes each and
 * returns a pointer to the allocated memory. The memory is set to zero.
 * If nmemb or size is 0, then calloc() returns either NULL, or a unique pointer
 * value that can later be successfully passed to free(). If the multiplication
 * of nmemb and size would result in integer overflow, then calloc() returns an
 * error.
 * @note Overflow check:
 * // `size * nmemb` peut overflow
 * if (size  * nmemb > INT_MAX)
 * // We divide both side by nmemb:
 * if (size          > INT_MAX / nmemb)
 * ```
*/
void	*ft_calloc(size_t nmemb, size_t size, t_list **ptr_list)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (ft_malloc(0, ptr_list));
	if (size > __SIZE_MAX__ / nmemb)
		return (NULL);
	ptr = ft_malloc(nmemb * size, ptr_list);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/**
 * Reallocate memory and exit the program if it fails.
 * *ptr can be NULL, in which case it will be allocated. If size is 0, *ptr will
 * be freed and set to NULL.
*/
void	*ft_realloc(void *ptr, size_t size, size_t old_size, t_list **ptr_list)
{
	char	*new_ptr;

	new_ptr = NULL;
	if (size > 0)
	{
		new_ptr = ft_malloc(size, ptr_list);
		if (ptr)
			ft_memmove(new_ptr, ptr, fmin(size, old_size));
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
