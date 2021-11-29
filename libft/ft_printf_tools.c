/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:37:45 by dchonvil          #+#    #+#             */
/*   Updated: 2021/09/16 23:17:29 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(char *str)
{
	int	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

void	ft_putchar_spe(int l, int *i)
{
	write(1, &l, 1);
	*i += 1;
}

void	ft_putstr_spe(char *str, int *i)
{
	int	c;

	if (!str)
	{
		write(1, "(null)", 6);
		*i += 6;
		return ;
	}
	c = 0;
	while (str[c] != '\0')
	{
		ft_putchar_spe(str[c], i);
		c++;
	}
}

void	ft_putnbr_spe(int nb, int *i)
{
	int	n;
	int	modulo;

	n = 0;
	modulo = 1;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			ft_putstr_spe("-2147483648", i);
			return ;
		}
		nb *= -1;
		ft_putchar_spe('-', i);
	}
	while ((nb / modulo) >= 10)
		modulo = modulo * 10;
	while (modulo > 0)
	{
		n = ((nb / modulo) % 10) + '0';
		ft_putchar_spe(n, i);
		modulo = modulo / 10;
	}
}

void	ft_put_unsigned_nbr(unsigned int nb, int *i)
{
	int	n;
	int	modulo;

	n = 0;
	modulo = 1;
	while ((nb / modulo) >= 10)
		modulo = modulo * 10;
	while (modulo > 0)
	{
		n = ((nb / modulo) % 10) + '0';
		ft_putchar_spe(n, i);
		modulo = modulo / 10;
	}
}
