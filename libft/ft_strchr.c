/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 05:36:05 by dchonvil          #+#    #+#             */
/*   Updated: 2021/08/13 18:34:15 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedchar)
{
	char	*box;

	box = (char *)string;
	while (*box != searchedchar)
	{
		if (*box == '\0')
			return (NULL);
		box++;
	}
	return (&(*box));
}
