/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 22:20:36 by jgrimaud          #+#    #+#             */
/*   Updated: 2024/02/13 22:20:40 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocate a NULL-terminated 2d array and exit the program if it fails.
*/
void	**ft_malloc_2d(size_t size_y, size_t size_x, size_t element_size, t_list **ptr_list)
{
	void	**out;
	size_t	y;

	expect(size_y != 0, "ft_malloc_2d: size_y is 0", ptr_list);
	expect(size_x != 0, "ft_malloc_2d: size_x is 0", ptr_list);
	expect(element_size != 0, "ft_malloc_2d: element_size is 0", ptr_list);
	out = ft_malloc(sizeof(void *) * (size_y + 1), ptr_list);
	y = 0;
	while (y < size_y)
	{
		out[y] = ft_malloc(element_size * (size_x + 1), ptr_list);
		((char*)out[y])[element_size * size_x] = 0;
		y++;
	}
	out[size_y] = 0;
	return (out);
}

/**
 * Free a NULL-terminated 2d array and set it to NULL.
*/
void	ft_free_2d(void ***ptr, t_list **ptr_list)
{
	int		i;

	if (ptr && *ptr)
	{
		i = 0;
		while ((*ptr)[i])
			ft_free(&(*ptr)[i++], ptr_list);
		ft_free((void **)ptr, ptr_list);
	}
}
