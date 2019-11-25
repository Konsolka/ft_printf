/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:13:19 by mburl             #+#    #+#             */
/*   Updated: 2019/11/25 16:05:28 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_f(t_flags *flags, va_list args)
{
	char	*nb;
	int		size;
	long double	cast;

	if (flags->precision == -2)
		flags->precision = 0;
	else if (flags->precision <= 0)
		flags->precision = 6;
	else if (flags->precision > 20)
		flags->precision = 20;
	cast = va_arg(args, long double);
	if (flags->length != LEN_TYPE_L_LAR)
		cast = va_arg(args, double);
	size = sv_gcvt(cast, &nb, flags->precision, flags);
	if (flags->minus == 0)
		ft_pad(flags, size);
	ft_write(nb, size, flags);
	if (flags->minus == 1)
		ft_pad(flags, size);
	free(nb);
	return (size);
}
