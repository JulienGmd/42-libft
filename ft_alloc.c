/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:47:44 by jgrimaud          #+#    #+#             */
/*   Updated: 2024/02/13 19:47:44 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size > __SIZE_MAX__ / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
