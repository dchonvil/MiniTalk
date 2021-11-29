/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 02:14:10 by dchonvil          #+#    #+#             */
/*   Updated: 2021/08/13 18:38:49 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;
	size_t		j;
	char		*box;

	box = (char *)s1;
	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return (box);
	while (box[i])
	{
		while (j < len && s2[j] == box[i + j])
		{
			if (ft_strlen(s2) + i > len)
				return (0);
			if (s2[j + 1] == '\0' || j == len)
				return (box + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
