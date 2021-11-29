/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 07:23:45 by dchonvil          #+#    #+#             */
/*   Updated: 2021/10/30 04:13:57 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_next_line(char *save)
{
	int	c;

	if (!save)
		return (0);
	c = 0;
	while (save[c])
	{
		if (save[c] == '\n')
			return (1);
		c++;
	}
	return (0);
}

int	count_char(char *str)
{
	int	c;

	if (!str)
		return (0);
	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

void	*copy_mem(void *box, const void *src, int n)
{
	int	c;

	if (src == box)
		return (box);
	c = 0;
	if (src < box)
		while (n--)
			((char *)box)[n] = ((char *)src)[n];
	else
	{
		while (c < n)
		{
			((char *)box)[c] = ((char *)src)[c];
			c++;
		}
	}
	return (box);
}

char	*treatment(char *save, char *l)
{
	int		c;
	int		i;
	int		size;
	char	*box;

	if (!save && !l)
		return (NULL);
	c = count_char(save);
	i = count_char(l);
	size = c + i + 1;
	box = malloc(sizeof(char) * size);
	if (!box)
		return (NULL);
	copy_mem(box, save, c);
	copy_mem((box + c), l, i);
	box[size - 1] = '\0';
	free(save);
	return (box);
}

int	get_next_line(int fd, char **line)
{
	int			r;
	char		*l;
	static char	*save;

	l = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line || BUFFER_SIZE <= 0 || fd < 0 || !l)
		return (-1);
	r = 1;
	while (r != 0 && check_next_line(save) == 0)
	{
		r = read(fd, l, BUFFER_SIZE);
		if (r == -1)
		{
			free(l);
			return (-1);
		}
		l[r] = '\0';
		save = treatment(save, l);
	}
	free(l);
	*line = render(save);
	save = save_treat(save);
	if (r == 0)
		return (0);
	return (1);
}
