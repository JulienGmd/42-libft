/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:57:50 by jgrimaud          #+#    #+#             */
/*   Updated: 2023/11/13 10:59:57 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Locates the first occurrence of the null-terminated string little in the
 * string big, where not more than len characters are searched.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	while (big[i] && i + little_len <= len)
	{
		j = 0;
		while (big[i + j] && big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return (&((char *)big)[i]);
		}
		i++;
	}
	return (NULL);
}
