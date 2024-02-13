/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 22:09:54 by jgrimaud          #+#    #+#             */
/*   Updated: 2024/02/13 22:10:01 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clean_exit(int status, t_list **ptr_list)
{
	cleanup(ptr_list);
	exit(status);
}

void	clean_exit_with_error(char *msg, t_list **ptr_list)
{
	write_error("Error: ");
	write_error(msg);
	write_error("\n");
	clean_exit(1, ptr_list);
}
