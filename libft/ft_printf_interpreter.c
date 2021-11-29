/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 02:03:33 by dchonvil          #+#    #+#             */
/*   Updated: 2021/07/30 06:43:27 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_char(const char *print, va_list args, int c, int *i)
{
	int	n;

	n = '\0';
	if (print[c + 1] == 'c')
	{
		n = va_arg(args, int);
		ft_putchar_spe(n, i);
	}
	else if (print[c + 1] == 's')
		ft_putstr_spe(va_arg(args, char *), i);
}

void	check_nbr(const char *print, va_list args, int c, int *i)
{
	if (print[c + 1] == 'd' || print[c + 1] == 'i')
		ft_putnbr_spe(va_arg(args, int), i);
	else if (print[c + 1] == 'u')
		ft_put_unsigned_nbr(va_arg(args, unsigned int), i);
}

void	filler(char *box, const char *base, long long int nb)
{
	int	n;

	n = 0;
	while ((nb / 16) > 0)
	{
		box[n] = base[(nb % 16)];
		nb /= 16;
		n++;
	}
	box[n] = base[(nb % 16)];
	box[n + 1] = '\0';
}

char	*hexa_treatment(char type, const char *base, va_list args)
{
	int				n;
	char			*box;
	long long int	nb;
	long long int	check;

	if (type == 'p')
		nb = (unsigned long long int)va_arg(args, void *);
	else
		nb = (long long int)va_arg(args, int);
	n = 0;
	if (nb < 0)
		nb = 4294967295 - ((nb * -1) - 1);
	check = nb;
	while ((check / 16) > 0)
	{
		check /= 16;
		n++;
	}
	box = malloc(sizeof(char) * (n + 3));
	if (!box)
		return (NULL);
	filler(box, base, nb);
	return (box);
}

void	put_hexa(const char *print, va_list args, int c, int *i)
{
	int			n;
	char		*box;
	char const	*base;

	if (print[c + 1] == 'x' || print[c + 1] == 'p')
		base = "0123456789abcdef";
	else if (print[c + 1] == 'X')
		base = "0123456789ABCDEF";
	if (print[c + 1] == 'p')
		ft_putstr_spe("0x", i);
	box = hexa_treatment(print[c + 1], base, args);
	if (!box)
	{
		ft_putchar_spe('0', i);
		return ;
	}
	n = ft_count(box);
	while (n > 0)
	{
		n--;
		ft_putchar_spe (box[n], i);
	}
	free(box);
}
