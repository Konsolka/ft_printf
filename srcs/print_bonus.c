/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenton <abenton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:51:14 by abenton           #+#    #+#             */
/*   Updated: 2019/12/04 16:40:33 by abenton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_n(t_flags *flags, va_list args)
{
	int		*n;

	n = va_arg(args, int*);
	*n = flags->byte_total;
	return (0);
}

/*
**	длина чсила в двоичном виде
*/

static int		ft_nbr_len(intmax_t nbr, int base)
{
	int		i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

/*
**	nbr_len - number length
**	len - string length
*/

int				print_b(t_flags *flags, va_list args)
{
	intmax_t	nbr;
	int			nbr_len;
	int			len;

	if (flags->precision != 0)
		flags->zero = 0;
	len = 0;
	nbr = get_number_u(flags, args);
	if (flags->precision >= 0 || nbr > 0)
		ft_nbr_len(nbr, 2);
	if (flags->hash && (nbr > 0 || flags->precision < 0))
		len += 1;
	nbr_len = len;
	len = (flags->precision > len) ? flags->precision : len;
	if (flags->width && !flags->minus)
		len = ft_pad(flags, len);
	if (flags->hash && (nbr > 0 || flags->precision < 0))
		ft_write("0", 1, flags);
	while (nbr_len++ < flags->precision)
		ft_write("0", 1, flags);
	if (flags->precision >= 0 || nbr > 0)
		ft_putnbr_maxint_u(nbr, "01", 2, flags);
	if (flags->width && flags->minus)
		len = ft_pad(flags, len);
	return (len);
}
