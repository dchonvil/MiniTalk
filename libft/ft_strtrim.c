/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:06:00 by dchonvil          #+#    #+#             */
/*   Updated: 2021/08/13 19:53:54 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_is_in_set(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char	*trim_treat(char const *s1, char const *set, int i)
{
	unsigned int	size;
	char			*start;
	char			*dest;
	char			*end;

	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_is_in_set(s1[i], set))
		i++;
	start = (char *)&s1[i];
	i = ft_strlen((char *)s1) - 1;
	if (i != -1)
		while (i >= 0 && ft_is_in_set(s1[i], set))
			i--;
	end = (char *)&s1[i];
	if (!*s1 || end == start)
		size = 2;
	else
		size = end - start + 2;
	dest = malloc(sizeof(char) * size);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, start, size);
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;

	dest = trim_treat(s1, set, 0);
	return (dest);
}
