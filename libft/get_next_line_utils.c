/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:36:02 by dchonvil          #+#    #+#             */
/*   Updated: 2021/10/30 04:05:07 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	saver(char *save, char *box, int c)
{
	int	i;

	i = 0;
	while (save[c] != '\0')
	{
		box[i] = save[c];
		c++;
		i++;
	}
	box[i] = '\0';
}

char	*save_treat(char *save)
{
	int		c;
	int		i;
	char	*box;

	if (!save)
		return (NULL);
	c = 0;
	i = 0;
	while (save[c] != '\0' && save[c] != '\n')
		c++;
	if (!save[c])
	{
		free(save);
		return (NULL);
	}
	while (save[i] != '\0')
		i++;
	box = malloc(sizeof(char) * ((i - c) + 1));
	if (!box)
		return (NULL);
	c++;
	saver(save, box, c);
	free(save);
	return (box);
}

char	*render(char *save)
{
	int		c;
	char	*box;

	if (!save)
		return (NULL);
	c = 0;
	while (save[c] && save[c] != '\n')
		c++;
	box = malloc(sizeof(char) * (c + 1));
	if (!box)
		return (NULL);
	c = 0;
	while (save[c] && save[c] != '\n')
	{
		box[c] = save[c];
		c++;
	}
	box[c] = '\0';
	return (box);
}
