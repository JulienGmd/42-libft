/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 22:09:54 by jgrimaud          #+#    #+#             */
/*   Updated: 2024/04/08 19:23:49 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clean_exit(int status, void *data)
{
	cleanup(data);
	exit(status);
}

void	clean_exit_with_error(char *msg, void *data)
{
	write_error("Error: ");
	write_error(msg);
	write_error("\n");
	clean_exit(1, data);
}
