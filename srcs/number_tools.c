/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:31:08 by mburl             #+#    #+#             */
/*   Updated: 2019/12/05 11:30:38 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		get_number(t_flags *flags, va_list args)
{
	intmax_t	num;

	num = va_arg(args, intmax_t);
	if (flags->length == LEN_TYPE_HH)
		num = (signed char)num;
	else if (flags->length == LEN_TYPE_H)
		num = (short)num;
	else if (flags->length == LEN_TYPE_LL)
		num = (long long)num;
	else if (flags->length == LEN_TYPE_L)
		num = (long)num;
	else if (flags->length == LEN_TYPE_J)
		num = (intmax_t)num;
	else if (flags->length == LEN_TYPE_Z)
		num = (size_t)num;
	else
		num = (int)num;
	return (num);
}

uintmax_t		get_number_u(t_flags *flags, va_list args)
{
	uintmax_t	num;

	num = va_arg(args, uintmax_t);
	if (flags->length == LEN_TYPE_HH)
		num = (unsigned char)num;
	else if (flags->length == LEN_TYPE_H)
		num = (unsigned short)num;
	else if (flags->length == LEN_TYPE_LL)
		num = (unsigned long long)num;
	else if (flags->length == LEN_TYPE_L)
		num = (unsigned long)num;
	else if (flags->length == LEN_TYPE_J)
		num = (uintmax_t)num;
	else if (flags->length == LEN_TYPE_Z)
		num = (size_t)num;
	else
		num = (unsigned int)num;
	return (num);
}

void			get_number_size(uintmax_t nb, uintmax_t str_len, int *size)
{
	*size += 1;
	while (nb >= str_len)
	{
		nb /= str_len;
		*size += 1;
	}
}

void			display_sign(intmax_t nb, t_flags *flags)
{
	if (nb < 0)
		ft_write("-", 1, flags);
	if (flags->plus && nb >= 0)
		ft_write("+", 1, flags);
	else if (flags->space && nb >= 0)
		ft_write(" ", 1, flags);
}

void			ft_putnbr_maxint_u(uintmax_t nb, char *str,
								uintmax_t str_len, t_flags *flags)
{
	if (nb >= str_len)
		ft_putnbr_maxint_u(nb / str_len, str, str_len, flags);
	ft_write_char(str[nb % str_len], flags);
}
