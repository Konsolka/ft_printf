/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenton <abenton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:51:14 by abenton           #+#    #+#             */
/*   Updated: 2019/11/29 16:59:35 by abenton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int         print_n(t_flags *flags, va_list args)
{
	int     *n;

	n = va_arg(args, int*);
	*n = flags->byte_total;
	return (0);
}

/*
	перевод числа в двоичное

static int		ft_base(intmax_t value, int base, t_flags *flags)
{
	int 		len;
	intmax_t 	value2;
	char		*result;
	char		*result2;

	len = 1;
	value2 = value;
	while (value2 /= base)
		len++;
	if ((result = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	result2 = ft_strdup("0123456789abcdef");
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = result2[value % base];
		value /= base;
	}
	len = ft_strlen(result);
	ft_write(result, len, flags);
	free(result);
	free(result2);
	return (len);
}
*/

/*
	длина чсила в двоичном виде
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

int			print_b(t_flags *flags, va_list args)
{
	intmax_t 	nbr;
	int			nbr_len; // длина числа в двоичном виде
	int			len; // длина всего
	int			width;

	nbr = va_arg(args, unsigned int);
	nbr_len = ft_nbr_len(nbr, 2);
	len = 0;
	len = nbr_len + ((flags->precision == -1) ? 0 : len);
	if (flags->space)
	{
		ft_write(" ", 1, flags);
		len += 1;
	}
	if (flags->precision > 0 && flags->precision < len && len > 0)
		len = flags->precision;
	if (flags->width)
	{
		if (flags->minus)
			ft_putnbr_maxint_u(nbr, "01", 2, flags);
		width = 0;
		while (width++ < flags->width - len)
			ft_write((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
	}
	if (!flags->width || !flags->minus)
		ft_putnbr_maxint_u(nbr, "01", 2, flags);
	return (len);
}
