/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:58:04 by jgrimaud          #+#    #+#             */
/*   Updated: 2023/11/15 18:35:36 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	nbr;

	sign = 1;
	nbr = 0;
	while (ft_isspace(nptr[0]))
		nptr++;
	if (nptr[0] == '+' || nptr[0] == '-')
	{
		if (nptr[0] == '-')
			sign = -sign;
		nptr++;
	}
	while (ft_isdigit(nptr[0]))
	{
		if (nbr > (LONG_MAX - (nptr[0] - '0')) / 10)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		nbr = nbr * 10 + nptr[0] - '0';
		nptr++;
	}
	return (sign * nbr);
}
