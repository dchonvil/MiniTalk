/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 01:10:19 by dchonvil          #+#    #+#             */
/*   Updated: 2021/02/21 04:34:54 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*box;

	if (!lst)
		return ;
	box = lst;
	(*f)(box->content);
	while (box->next != NULL)
	{
		(*f)(box->next->content);
		box = box->next;
	}
}
