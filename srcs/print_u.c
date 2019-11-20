/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:30:04 by mburl             #+#    #+#             */
/*   Updated: 2019/11/20 15:30:11 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_u(t_flags *flags, va_list args)
{
	uintmax_t	nb;
	int			size;
	int			nb_size;

	if (flags->precision != 0)
		flags->zero = 0;
	size = 0;
	nb = get_number_u(flags, args);
	if (flags->precision >= 0 || nb > 0)
		get_number_size(nb , 10, &size);
	if (flags->hash && (nb > 0 || flags->precision < 0))
		size += 1;
	nb_size = size;
	size = (flags->precision > size) ? flags->precision : size;
	if (flags->width && !flags->minus)
		size = ft_pad(flags, size);
	if (flags->hash && (nb > 0 || flags->precision < 0))
		ft_write("0", 1, flags);
	while (nb_size++ < flags->precision)
		ft_write("0", 1, flags);
	if (flags->precision >= 0 || nb > 0)
		ft_putnbr_maxint_u(nb, "0123456789", 10, flags);
	if (flags->width && flags->minus)
		size = ft_pad(flags, size);
	return (size);
}
