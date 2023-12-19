/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:03:09 by jgrimaud          #+#    #+#             */
/*   Updated: 2023/12/19 07:07:54 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split_allocate_strs(char const *s, char c)
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
	return (malloc(sizeof(char *) * (num_str + 1)));
}

static char	**ft_split_free(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	*last_delimiter;
	size_t	i;

	if (!s)
		return (NULL);
	strs = ft_split_allocate_strs(s, c);
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
			strs[i] = ft_substr(last_delimiter + 1, 0, s - last_delimiter);
			if (!strs[i++])
				return (ft_split_free(strs));
		}
		s++;
	}
	strs[i] = 0;
	return (strs);
}

char	**ft_safe_split(char const *s, char c)
{
	char	**out;

	out = ft_split(s, c);
	if (!out)
		exit(1);
	return (out);
}
