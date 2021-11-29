/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:46:11 by dchonvil          #+#    #+#             */
/*   Updated: 2021/02/18 19:34:09 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*box;

	if (!(*alst))
		return ;
	box = *alst;
	if (!box)
	{
		box = new;
		return ;
	}
	while (box->next != NULL)
		box = box->next;
	box->next = new;
}
