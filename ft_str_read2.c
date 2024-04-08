/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_read2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:45:46 by jgrimaud          #+#    #+#             */
/*   Updated: 2024/04/08 19:26:05 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @return the index of the first occurence of c in str or -1 if not found.
 */
size_t	ft_index_of(char *str, char c)
{
	size_t	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}
