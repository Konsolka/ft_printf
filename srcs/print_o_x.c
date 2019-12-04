/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:27:22 by mburl             #+#    #+#             */
/*   Updated: 2019/12/04 12:12:52 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_o(t_flags *flags, va_list args)
{
	uintmax_t	nb;
	int			size;
	int			nb_size;

	if (flags->precision != 0)
		flags->zero = 0;
	size = 0;
	nb = get_number_u(flags, args);
	if (flags->precision >= 0 || nb > 0)
		get_number_size(nb, 8, &size);
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
		ft_putnbr_maxint_u(nb, "01234567", 8, flags);
	if (flags->width && flags->minus)
		size = ft_pad(flags, size);
	return (size);
}

static void		print_hash_key(char *hash, t_flags *flags,
								uintmax_t nb, int size)
{
	if ((flags->zero && flags->hash == 1 && nb != 0 &&
			!flags->minus && flags->type != 'p') ||
			(flags->type == 'p' && flags->minus))
		ft_write(hash, 2, flags);
	if (flags->width && !flags->minus)
		size = ft_pad(flags, size);
	if ((flags->hash == 1 && nb != 0 && !flags->zero && flags->type != 'p') ||
			(flags->type == 'p' && !flags->minus))
		ft_write(hash, 2, flags);
}

int				print_x(t_flags *flags, va_list args)
{
	uintmax_t	nb;
	int			size;
	int			nb_size;

	if (flags->precision != 0)
		flags->zero = 0;
	size = 0;
	nb = get_number_u(flags, args);
	if (flags->precision >= 0 || nb > 0)
		get_number_size(nb, 16, &size);
	nb_size = size;
	if ((flags->hash && nb > 0) || flags->type == 'p')
		size += 2;
	size += (flags->precision > size) ? flags->precision - nb_size : 0;
	size = (flags->precision > size) ? flags->precision : size;
	print_hash_key("0x", flags, nb, size);
	while (nb_size++ < flags->precision)
		ft_write("0", 1, flags);
	if (flags->precision >= 0 || nb > 0)
		ft_putnbr_maxint_u(nb, "0123456789abcdef", 16, flags);
	if (flags->width && flags->minus)
		size = ft_pad(flags, size);
	return (size);
}

int				print_x_upper(t_flags *flags, va_list args)
{
	uintmax_t	nb;
	int			size;
	int			nb_size;

	if (flags->precision != 0)
		flags->zero = 0;
	size = 0;
	nb = get_number_u(flags, args);
	if (flags->precision >= 0 || nb > 0)
		get_number_size(nb, 16, &size);
	nb_size = size;
	if ((flags->hash && nb > 0) || flags->type == 'p')
		size += 2;
	size += (flags->precision > size) ? flags->precision - nb_size : 0;
	size = (flags->precision > size) ? flags->precision : size;
	print_hash_key("0X", flags, nb, size);
	while (nb_size++ < flags->precision)
		ft_write("0", 1, flags);
	if (flags->precision >= 0 || nb > 0)
		ft_putnbr_maxint_u(nb, "0123456789ABCDEF", 16, flags);
	if (flags->width && flags->minus)
		size = ft_pad(flags, size);
	return (size);
}
