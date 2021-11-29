/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:26:06 by dchonvil          #+#    #+#             */
/*   Updated: 2021/11/29 05:55:13 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_letter(char charset, char letter)
{
	if (charset == letter)
		return (1);
	return (0);
}

static int	count_char(char const *str, char letter)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str && check_letter(*str, letter))
			str++;
		if (*str && !check_letter(*str, letter))
		{
			i++;
			while (*str && !check_letter(*str, letter))
				str++;
		}
	}
	return (i);
}

static char	*tab_alloc(char const *s, char c)
{
	int		i;
	char	*box;

	i = 0;
	while (s[i] && !check_letter(s[i], c))
		i++;
	box = malloc(sizeof(char) * (i + 1));
	if (!box)
		return (NULL);
	i = 0;
	while (s[i] && !check_letter(s[i], c))
	{
		box[i] = s[i];
		i++;
	}
	box[i] = '\0';
	return (box);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**box;

	box = malloc(sizeof(char *) * (count_char(s, c) + 1));
	if (!box || !s)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && check_letter(*s, c))
			s++;
		if (*s && !check_letter(*s, c))
		{
			box[i] = tab_alloc(s, c);
			if (box[i] == NULL)
				return (NULL);
			i++;
			while (*s && !check_letter(*s, c))
				s++;
		}
	}
	box[i] = NULL;
	return (box);
}
