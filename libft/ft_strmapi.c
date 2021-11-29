/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 23:42:16 by dchonvil          #+#    #+#             */
/*   Updated: 2021/08/13 18:37:28 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		c;
	static char			*box;

	c = 0;
	while (s[c] != '\0')
		c++;
	box = malloc(sizeof(char) * (c + 1));
	if (!box)
		return (NULL);
	c = 0;
	while (s[c] != '\0')
	{
		box[c] = (*f)(c, s[c]);
		c++;
	}
	box[c] = '\0';
	return (box);
}
