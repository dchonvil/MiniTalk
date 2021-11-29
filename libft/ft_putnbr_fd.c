/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 01:25:12 by dchonvil          #+#    #+#             */
/*   Updated: 2021/02/17 01:51:53 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				modulo;
	char			c;
	long int		i;

	c = '\0';
	i = n;
	modulo = 1;
	if (i < 0)
	{
		if (i == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		i *= -1;
		write(fd, "-", 1);
	}
	while ((i / modulo) >= 10)
		modulo = modulo * 10;
	while (modulo > 0)
	{
		c = ((i / modulo) % 10) + '0';
		write(fd, &c, 1);
		modulo = modulo / 10;
	}
}
