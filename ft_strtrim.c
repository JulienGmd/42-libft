/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:02:42 by jgrimaud          #+#    #+#             */
/*   Updated: 2023/11/20 19:40:26 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return ((char *)s1);
	if (ft_strlen(s1) == 0)
		return (ft_calloc(1, 1));
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (i > 0 && ft_strchr(set, s1[i]))
		i--;
	end = i;
	if (end >= start)
		return (ft_substr(s1, start, end - start + 1));
	else
		return (ft_calloc(1, 1));
}
