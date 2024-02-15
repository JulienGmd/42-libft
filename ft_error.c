/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 22:25:07 by jgrimaud          #+#    #+#             */
/*   Updated: 2024/02/15 04:40:44 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	write_error(char *msg)
{
	return (write(2, msg, ft_strlen(msg)));
}

void	expect(int condition, char *msg, t_list **ptr_list)
{
	if (!condition)
		clean_exit_with_error(msg, ptr_list);
}
