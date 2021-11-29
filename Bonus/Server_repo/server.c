/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:23:50 by dchonvil          #+#    #+#             */
/*   Updated: 2021/10/30 05:45:07 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

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

void	get_server_signal(int s, siginfo_t *infos)
{
	if (s == SIGUSR1)
	{
		put_signal(0);
		if (kill(infos->si_pid, SIGUSR1) == -1)
		{
			ft_printf("An error occurred while returning signal\n");
			exit(1);
		}
	}
	else if (s == SIGUSR2)
	{
		put_signal(1);
		if (kill(infos->si_pid, SIGUSR2) == -1)
		{
			ft_printf("An error occurred while returning signal\n");
			exit(1);
		}
	}
	usleep(500);
}

int	main(void)
{
	struct sigaction	infos;

	ft_printf("PID : %d\n", getpid());
	infos.sa_sigaction = (void *)get_server_signal;
	infos.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &infos, NULL) < 0)
	{
		ft_printf("An error occurred on signal SIGUSR1\n");
		exit(1);
	}
	if (sigaction(SIGUSR2, &infos, NULL) < 0)
	{
		ft_printf("An error occurred on signal SIGUSR2\n");
		exit(1);
	}
	signal(SIGWINCH, SIG_IGN);
	while (1)
		pause();
	return (0);
}
