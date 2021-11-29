/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 14:33:00 by dchonvil          #+#    #+#             */
/*   Updated: 2021/10/28 00:16:41 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	decimal(int nb)
{
	int	modulo;

	modulo = 1;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		nb *= -1;
		ft_putchar('-');
	}
	while ((nb / modulo) >= 10)
	{
		modulo = modulo * 10;
	}
	while (modulo > 0)
	{
		ft_putchar((nb / modulo) % 10 + '0');
		modulo = modulo / 10;
	}
}

static void	convert(char *base, long int nb, int num)
{
	int		c;
	char	str[255];

	c = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	while (nb > 0)
	{
		str[c] = base[(nb % num)];
		nb = nb / num;
		c++;
	}
	c = c - 1;
	while (c >= 0)
	{
		ft_putchar(str[c]);
		c--;
	}
}

static int	treatment(char *base, int num)
{
	int		c;
	char	box[255];

	c = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[num] != '\0')
	{
		if (base[num] == '+' || base[num] == '-')
			return (0);
		while (box[c] != '\0')
		{
			if (box[c] == base[num])
				return (0);
			c++;
		}
		c = 0;
		box[num] = base[num];
		num++;
	}
	return (num);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			num;
	int			check;
	long int	n;

	n = nbr;
	num = 0;
	check = treatment(base, num);
	if (check == 0)
		return ;
	else if (check == 10)
		decimal(n);
	else
		convert(base, n, check);
}
