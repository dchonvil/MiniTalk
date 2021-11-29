/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 05:46:16 by dchonvil          #+#    #+#             */
/*   Updated: 2021/07/30 06:42:09 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *print, ...);
int		ft_count(char *str);
void	ft_putnbr_spe(int nb, int *i);
void	ft_putchar_spe(int l, int *i);
void	ft_putstr_spe(char *str, int *i);
void	ft_put_unsigned_nbr(unsigned int nb, int *i);
void	print_treatment(const char *print, va_list args, int *i);
void	put_hexa(const char *print, va_list args, int c, int *i);
void	check_arg(const char *print, va_list args, int c, int *i);
void	check_nbr(const char *print, va_list args, int c, int *i);
void	check_char(const char *print, va_list args, int c, int *i);
void	filler(char *box, const char *base, long long int nb);
char	*hexa_treatment(char type, const char *base, va_list args);

#endif
