/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 06:24:14 by dchonvil          #+#    #+#             */
/*   Updated: 2021/08/13 18:39:37 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedchar)
{
	int	c;

	c = 0;
	while (string[c] != '\0')
		c++;
	while (c >= 0)
	{
		if (string[c] == searchedchar)
			return ((char *)&string[c]);
		c--;
	}
	return (NULL);
}
