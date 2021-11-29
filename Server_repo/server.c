/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:23:50 by dchonvil          #+#    #+#             */
/*   Updated: 2021/10/30 05:27:57 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	put_signal(int b)
{
	static int				c = 0;
	static unsigned char	l = 0;

	l |= (b << c++);
	if (c > 7)
	{
		if (l == '\0')
			ft_printf("\n=====================\n");
		else
			ft_printf("%c", l);
		c = 0;
		l = 0;
	}
}

void	get_signals(int s)
{
	if (s == SIGUSR1)
		put_signal(0);
	else if (s == SIGUSR2)
		put_signal(1);
}

int	main(void)
{
	ft_printf("PID : %d\n", getpid());
	if (signal(SIGUSR1, get_signals) == SIG_ERR)
	{
		ft_printf("An error occurred on signal SIGUSR1\n");
		exit(1);
	}
	if (signal(SIGUSR2, get_signals) == SIG_ERR)
	{
		ft_printf("An error occurred on signal SIGUSR2\n");
		exit(1);
	}
	signal(SIGWINCH, SIG_IGN);
	while (1)
		pause();
	return (0);
}
