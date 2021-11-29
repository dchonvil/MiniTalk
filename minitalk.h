/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:36:41 by dchonvil          #+#    #+#             */
/*   Updated: 2021/10/30 03:56:31 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_printf(const char *print, ...);
int		ft_isnumber(const char *str);
void	get_signal(int s, siginfo_t *infos);

#endif
