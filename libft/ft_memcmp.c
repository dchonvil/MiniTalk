/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 07:15:50 by dchonvil          #+#    #+#             */
/*   Updated: 2021/08/13 18:16:41 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)p1;
	str2 = (unsigned char *)p2;
	if (str1 == str2 || size == 0)
		return (0);
	while (*str1 == *str2 && size - 1)
	{
		str1++;
		str2++;
		size--;
	}
	if (size)
		return (*str1 - *str2);
	return (0);
}
