/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:56:05 by jgrimaud          #+#    #+#             */
/*   Updated: 2023/11/17 18:22:22 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @return a pointer to the first occurrence of the character c in the string s.
 * @note The terminating null byte is considered part of the string, so that if
 * c is specified as '\0', these functions return a pointer to the terminator.
*/
char	*ft_strchr(const char *s, int c)
{
	int	i;

	if ((char)c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
