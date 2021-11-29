/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 05:11:40 by dchonvil          #+#    #+#             */
/*   Updated: 2021/08/13 20:04:17 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*subtreat(char const *s, unsigned int st, size_t sz, size_t len)
{
	size_t	i;
	char	*box;

	i = 0;
	box = ft_calloc(sz, sizeof(char));
	if (!box)
		return (NULL);
	if (sz == 1)
	{
		box[0] = '\0';
		return (box);
	}
	while (i < len)
	{
		box[i] = s[st + i];
		i++;
	}
	box[i] = '\0';
	return (box);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*box;
	size_t		s_len;
	size_t		size;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		size = 1;
	else
		size = len + 1;
	box = subtreat(s, start, size, len);
	return (box);
}
