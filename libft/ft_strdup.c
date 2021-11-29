/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 04:43:05 by dchonvil          #+#    #+#             */
/*   Updated: 2021/02/14 05:07:25 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	unsigned int	c;
	char			*box;

	c = 0;
	while (source[c] != '\0')
		c++;
	box = malloc(sizeof(char) * (c + 1));
	if (box == NULL)
		return (NULL);
	c = 0;
	while (source[c] != '\0')
	{
		box[c] = source[c];
		c++;
	}
	box[c] = '\0';
	return (box);
}
