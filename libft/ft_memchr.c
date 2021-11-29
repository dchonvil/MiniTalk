/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 04:28:35 by dchonvil          #+#    #+#             */
/*   Updated: 2021/08/13 18:15:15 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mb, int sc, size_t size)
{
	char			*s;
	unsigned long	i;

	s = (char *)mb;
	i = 0;
	while (i < size)
	{
		if (s[i] == sc)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
