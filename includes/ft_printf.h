/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:37:38 by mburl             #+#    #+#             */
/*   Updated: 2019/12/04 11:44:27 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>

# define BUFF_SIZE 64
# define ARGS 22

# define LEN_TYPE_H 0
# define LEN_TYPE_L_LAR 1
# define LEN_TYPE_J 2
# define LEN_TYPE_L 3
# define LEN_TYPE_Z 4
# define LEN_TYPE_LL 5
# define LEN_TYPE_HH 6

typedef struct	s_flags
{
	int		hash;
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		width;
	int		precision;
	int		length;
	char	type;
	char	buff[BUFF_SIZE];
	int		byte;
	int		byte_total;
}				t_flags;

typedef struct	s_type
{
	char	name;
	int		(*f)();
}				t_type;

int		ft_printf(const char * restrict format, ...);
int		ft_pad(t_flags *flags, int size);
int		ft_write(void *s, int size, t_flags *flags);
int		write_untill(char **format, t_flags *flags);
int		call_type(char **str, va_list args, t_flags *flags);
int		handle_flags(char **str, t_flags *flags);
int		handle_width(char **str, t_flags *flags, va_list args);
int		handle_precision(char **str, t_flags *flags, va_list args);
int		handle_length(char **str_c, t_flags *flags);
int		print_o(t_flags *flags, va_list args);
int		print_u(t_flags *flags, va_list args);
int		print_d(t_flags *flags, va_list args);
int		print_s(t_flags *flags, va_list args);
int		print_x(t_flags *flags, va_list args);
int		print_s(t_flags	*flags, va_list args);
int		print_x_upper(t_flags *flags, va_list args);
int		print_p(t_flags *flags, va_list args);
int		print_f(t_flags *flags, va_list args);
int     print_c(t_flags	*flags, va_list args);
int		ft_write_char(char c, t_flags *flags);
void	display_sign(intmax_t nb, t_flags *flags);
void	get_number_size(uintmax_t nb, uintmax_t str_len, int *size);
uintmax_t	get_number_u(t_flags *flags, va_list args);
intmax_t     get_number(t_flags *flags, va_list args);
void	ft_putnbr_maxint_u(uintmax_t nb, char *str, uintmax_t str_len, t_flags *flags);
int		ft_pad_nb(t_flags *flags, va_list args, char *base, char *hash_key);
int		ft_gcvt(long double f, char **s, t_flags *flags);
int		print_n(t_flags *flags, va_list args);
int		print_b(t_flags *flags, va_list args);
#endif