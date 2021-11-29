/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:30:16 by dchonvil          #+#    #+#             */
/*   Updated: 2021/10/30 05:33:15 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	set_signal(int b, int s_pid)
{
	if (b == 0)
	{
		if (kill(s_pid, SIGUSR1) == -1)
		{
			ft_printf("An error occurred while sending SIGUSR1\n");
			exit(1);
		}
	}
	else if (b == 1)
	{
		if (kill(s_pid, SIGUSR2) == -1)
		{
			ft_printf("An error occurred while sending SIGUSR2\n");
			exit(1);
		}
	}
}

void	client_treat(char *str, int s_pid)
{
	int		b;
	int		c;
	char	l;

	c = 0;
	l = 0;
	b = 0;
	while (str[c] != '\0')
	{
		while (l < 8)
		{
			b = (str[c] >> l++) & 1;
			usleep(500);
			set_signal(b, s_pid);
		}
		c++;
		l = 0;
	}
	while (l < 8)
	{
		b = (0 >> l++) & 1;
		usleep(500);
		set_signal(b, s_pid);
	}
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

int	check_arg_client(int argc, char **argv)
{
	if (argc < 3)
	{
		ft_printf("\nAborted : Missing parameter\n");
		ft_printf("USAGE : ./client [server_pid] [message]\n");
		return (1);
	}
	else if (argc > 3)
	{
		ft_printf("\nAborted : The script accepts only two parameters\n");
		ft_printf("USAGE : ./client [server_pid] [message]\n");
		return (2);
	}
	else if (ft_isnumber(argv[1]) == 0 )
	{
		ft_printf("\nAborted : The argument is not a valid pid\n");
		return (3);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int					server_pid;

	server_pid = check_arg_client(argc, argv);
	if (server_pid != 0)
		return (server_pid);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		ft_printf("This Server_pid is not valid\n");
	client_treat(argv[2], server_pid);
	return (0);
}
