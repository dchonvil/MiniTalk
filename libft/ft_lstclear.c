/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 21:31:56 by dchonvil          #+#    #+#             */
/*   Updated: 2021/08/13 15:17:37 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*box;

	if (!del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		box = *lst;
		*lst = box->next;
		free(box);
	}
	*lst = NULL;
}
