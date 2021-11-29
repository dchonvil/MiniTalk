/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:36:26 by dchonvil          #+#    #+#             */
/*   Updated: 2021/10/30 03:52:48 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

void	get_signal(int s, siginfo_t *infos)
{
	(void)infos;
	if (s == SIGTERM)
		signal(SIGTERM, SIG_IGN);
	ft_printf("+");
	usleep(500);
}

int	ft_isnumber(const char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if (ft_isdigit(str[c]) == 0)
			return (0);
		c++;
	}
	return (1);
}
