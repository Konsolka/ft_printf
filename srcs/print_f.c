/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:13:19 by mburl             #+#    #+#             */
/*   Updated: 2019/11/18 15:21:12 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_f(t_flags *flags, va_list args)
{
	char	*nb;
	int		size;

	if (flags->precision <= 0)
		flags->precision = 7;
	size = ft_gcvt(va_arg(args, double), &nb, flags->precision);
	ft_write(nb, size, flags);
	free(nb);
	return (size);
}