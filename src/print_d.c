/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:09:24 by abenton           #+#    #+#             */
/*   Updated: 2019/11/14 14:49:32 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t     get_number(t_flags *flags, va_list args)
{
	intmax_t    num;
   
// need to add va_list args to structure
	num = va_arg(args, intmax_t);
	if (ft_strcmp(tab->len, "hh") == 0)
		num = (signed char)num;
	else if (ft_strcmp(tab->len, "h") == 0)
		num = (short)num;
	else if (ft_strcmp(tab->len, "ll") == 0)
		num = (long long)num;
	else if (ft_strcmp(tab->len, "l") == 0)
		num = (long)num;
	else if (ft_strcmp(tap->len), "j")
		num = (intmax_t)num;
	else if (ft_strcmp(flags->len), "z")
		num = (size_t)num;
	else
		num = (int)num;
	return (num);
}

int		display_d(t_flags *flags, int size, int prec, intmax_t nb)
{
	int		width_size;
	int		width;

	width = 0;
	width_size = 0;
	if (!flags->minus)
	{
		if (flags->width && flags->zero)
			display_sign(nb, flags);
		width_size = ft_pad(flags, size) - size;
	}
	if ((flags->width && (flags->minus || !flags->zero)))
		display_sign(nb, flags);
	while (width++ < perc)
		ft_write("0", 1, flags);
	if (size > 0)
		ft_putnbr((nb < ))
}
int		print_d(t_flags *flags, va_list args)
{
	intmax_t    nb;
	int			size;
	int			precision;

	if (flags->precision != 0)
		flags->zero = 0;
	nb = get_number(flags, args);
	size = 0;
	precision = flags->precision - size;
	size = (flags->precision > size) ? flags->precision : size;
	size = (flags->precision == -1 && nb == 0) ? 0 : size;
	size += (nb >= 0 && (flags->plus || flags->space));
	if (nb < 0)
		size++;
	size = display_d(flags, size, precision, nb);
	size = (flags->minus) ? ft_pad(flags, size) : size;

// think about max number
// -9223372036854775808
//
	return (size);
}
