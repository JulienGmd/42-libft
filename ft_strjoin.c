/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:02:13 by jgrimaud          #+#    #+#             */
/*   Updated: 2023/11/20 19:40:09 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	str_len;

	if (!s1 || !s2)
		return (NULL);
	str_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * str_len);
	if (!str)
		return (NULL);
	str[0] = '\0';
	ft_strlcat(str, s1, str_len);
	ft_strlcat(str, s2, str_len);
	return (str);
}
