/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_alloc2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:47:44 by jgrimaud          #+#    #+#             */
/*   Updated: 2024/02/14 00:59:35 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split_allocate_strs(char const *s, char c, t_list **ptr_list)
{
	size_t	num_str;
	size_t	i;

	num_str = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			num_str++;
		i++;
	}
	return (ft_malloc(sizeof(char *) * (num_str + 1), ptr_list));
}

char	**ft_split(char const *s, char c, t_list **ptr_list)
{
	char	**strs;
	char	*last_delimiter;
	size_t	i;

	if (!s)
		return (NULL);
	strs = ft_split_allocate_strs(s, c, ptr_list);
	if (!strs)
		return (NULL);
	last_delimiter = (char *)s - 1;
	i = 0;
	while (s[0])
	{
		if (s[0] == c)
			last_delimiter = (char *)s;
		else if (s[1] == c || s[1] == '\0')
		{
			strs[i] = ft_substr(last_delimiter + 1, 0, s - last_delimiter, ptr_list);
			if (!strs[i++])
				return (ft_free_2d((void ***)&strs, ptr_list), NULL);
		}
		s++;
	}
	strs[i] = 0;
	return (strs);
}
