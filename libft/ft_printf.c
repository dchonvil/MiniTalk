/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:28:43 by dchonvil          #+#    #+#             */
/*   Updated: 2021/08/13 20:47:02 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_arg(const char *print, va_list args, int c, int *i)
{
	if (print[c + 1] == 'c' || print[c + 1] == 's')
		check_char(print, args, c, i);
	else if (print[c + 1] == 'p' || print[c + 1] == 'x' || print[c + 1] == 'X')
		put_hexa(print, args, c, i);
	else if (print[c + 1] == 'd' || print[c + 1] == 'i' || print[c + 1] == 'u')
		check_nbr(print, args, c, i);
}

void	print_treatment(const char *print, va_list args, int *i)
{
	int	c;

	c = 0;
	while (print[c] != '\0')
	{
		if (print[c] == '%')
		{
			if (print[c + 1] == '%')
				ft_putchar_spe(print[c + 1], i);
			else
				check_arg(print, args, c, i);
			c++;
		}
		else
			ft_putchar_spe(print[c], i);
		c++;
	}
}

int	ft_printf(const char *print, ...)
{
	int		i;
	va_list	args;

	if (!print)
		return (0);
	i = 0;
	va_start(args, print);
	print_treatment(print, args, &i);
	va_end(args);
	return (i);
}
