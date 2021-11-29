/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 05:57:39 by dchonvil          #+#    #+#             */
/*   Updated: 2021/08/13 18:35:23 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	treatment(char const *str, char *box, int offset)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		box[offset] = str[c];
		c++;
		offset++;
	}
	return (offset);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		c;
	int		i;
	char	*box;

	c = 0;
	i = 0;
	while (s1[c] != '\0')
		c++;
	while (s2[i] != '\0')
		i++;
	box = malloc(sizeof(char) * (c + i + 1));
	if (box == NULL)
		return (NULL);
	c = treatment(s1, box, 0);
	i = treatment(s2, box, c);
	box[i] = '\0';
	return (box);
}
