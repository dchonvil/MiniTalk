/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:26:53 by dchonvil          #+#    #+#             */
/*   Updated: 2021/02/17 18:48:30 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			c;
	unsigned long	i;
	unsigned long	n;

	c = 0;
	i = 0;
	while (src[c] != '\0')
		c++;
	while (dest[i] != '\0')
		i++;
	if (size == 0)
		return (c);
	else if (size < i)
		return (c + size);
	n = c + i;
	c = 0;
	while (i < (size - 1) && src[c] != '\0')
	{
		dest[i] = src[c];
		c++;
		i++;
	}
	dest[i] = '\0';
	return (n);
}
