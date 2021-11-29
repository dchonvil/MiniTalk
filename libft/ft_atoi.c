/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 03:15:41 by dchonvil          #+#    #+#             */
/*   Updated: 2021/08/13 14:23:31 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	treatment(char *box, int t, long int n)
{
	int	i;
	int	m;
	int	check;

	i = 0;
	m = 10;
	while (box[i] != '\0')
		i++;
	i = i - 1;
	check = i;
	while (i >= 0)
	{
		if (i < check)
		{
			n += (box[i] - 48) * m;
			m *= 10;
		}
		else
			n += box[i] - 48;
		i--;
	}
	if ((t % 2) == 1)
		n = n - (2 * n);
	return (n);
}

static int	check_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	extractor(char *box, const char *str, int c)
{
	int	i;
	int	r;

	i = 0;
	r = 1;
	while ((str[c] > 47 && str[c] < 58) && r == 1)
	{
		box[i] = str[c];
		if (i > 10)
			return (0);
		i++;
		if (str[c + 1] < 48 || str[c + 1] > 57)
			r = 0;
		c++;
	}
	box[i] = '\0';
	return (c);
}

int	ft_atoi(const char *str)
{
	int			c;
	int			i;
	char		box[12];
	long int	n;

	c = 0;
	i = 0;
	n = 0;
	while (check_space(str[c]))
		c++;
	if (!(str[c] == '+' || str[c] == '-' || (str[c] > 47 && str[c] < 58)))
		return (0);
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			i++;
		c++;
	}
	if (str[c] < 48 || str[c] > 57)
		return (0);
	c = extractor(box, str, c);
	if (c == 0)
		return (0);
	n = treatment(box, i, n);
	return (n);
}
