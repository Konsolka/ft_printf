/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:13:19 by mburl             #+#    #+#             */
/*   Updated: 2019/12/04 11:54:53 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>

int		print_f(t_flags *flags, va_list args)
{
	char			*nb;
	int				size;
	long double		cast;

	if (flags->precision == -2)
		flags->precision = 0;
	else if (flags->precision <= 0)
		flags->precision = 6;
	else if (flags->precision > 20)
		flags->precision = 20;
	if (flags->length == LEN_TYPE_L_LAR)
		cast = va_arg(args, long double);
	else
		cast = va_arg(args, double);
	size = ft_gcvt(cast, &nb, flags);
	if (cast != INFINITY)
		free(nb);
	return (size);
}
