/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_write2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:47:44 by jgrimaud          #+#    #+#             */
/*   Updated: 2024/02/14 06:30:23 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *), t_list **ptr_list)
{
	if (!lst || !*lst || !del)
		return ;
	if ((*lst)->next)
		ft_lstclear(&(*lst)->next, del, ptr_list);
	ft_lstdelone(*lst, del, ptr_list);
	*lst = NULL;
}
