/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:12:08 by dchonvil          #+#    #+#             */
/*   Updated: 2021/10/28 00:15:26 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_prime(int nb)
{
	int	c;
	int	n;

	if (nb < 2)
		return (0);
	c = 2;
	n = 1;
	while (c <= (nb / c))
	{
		if (nb % c == 0)
		{
			n = 0;
			return (n);
		}
		c++;
	}
	return (n);
}

int	ft_find_next_prime(int nb)
{
	while (!(ft_is_prime(nb)))
		nb++;
	return (nb);
}
