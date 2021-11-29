/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:03:52 by dchonvil          #+#    #+#             */
/*   Updated: 2021/02/18 18:21:57 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		c;
	t_list	*box;

	if (!lst)
		return (0);
	c = 1;
	box = lst->next;
	while (box != NULL)
	{
		box = box->next;
		c++;
	}
	return (c);
}
