/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 07:38:43 by dchonvil          #+#    #+#             */
/*   Updated: 2021/10/30 04:26:32 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rev_int_tab(int *tab, int size)
{
	int	c;
	int	i;
	int	*box;

	c = 0;
	box = malloc(sizeof(int) * (size + 1));
	if (!box)
		return ;
	i = size - 1;
	while (c < size)
	{
		box[c] = tab[i];
		c++;
		i--;
	}
	c = 0;
	while (c < size)
	{
		*(tab + c) = box[c];
		c++;
	}
	free(box);
}
