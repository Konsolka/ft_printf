/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:09:24 by abenton           #+#    #+#             */
/*   Updated: 2019/11/17 15:11:19 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t     get_number(t_flags *flags, va_list args)
{
	intmax_t    num;
   
// need to add va_list args to structure
	num = va_arg(args, intmax_t);
	if (flags->len == LEN_TYPE_HH)
		num = (signed char)num;
	else if (flags->len == LEN_TYPE_H)
		num = (short)num;
	else if (flags->len == LEN_TYPE_LL)
		num = (long long)num;
	else if (flags->len == LEN_TYPE_L)
		num = (long)num;
	else if (flags->len == LEN_TYPE_J)
		num = (intmax_t)num;
	else if (flags->len == LEN_TYPE_Z)
		num = (size_t)num;
	else
		num = (int)num;
	return (num);
}

int		ft_write_char(char c, t_flags *flags)
{
	return (ft_write(&c, 1, flags));
}

void	ft_putnbr_maxint_u(uintmax_t nb, char *str, uintmax_t str_len, t_flags *flags)
{
	if (nb >= str_len)
		ft_putnbr_maxint_u(nb / str_len, str, str_len, flags);
	ft_write_char(str[nb % str_len], flags);
}
void	display_sign(intmax_t nb, t_flags *flags)
{
	if (nb < 0)
		ft_write("-", 1, flags);
	if (flags->plus && nb >= 0)
		ft_write("+", 1, flags);
	else if (flags->space && nb >= 0)
		ft_write(" ", 1, flags);
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
	if ((flags->width && (flags->minus || !flags->zero)) || !flags->width)
		display_sign(nb, flags);
	while (width++ < prec)
		ft_write("0", 1, flags);
	if (size > 0) //&& ((flags->width || flags->precision)  && !flags->plus && nb) not and may be xor
		ft_putnbr_maxint_u((nb < 0 ? -nb : nb), "0123456789", 10, flags);
	return (size + width_size);
}

void	get_number_size(uintmax_t nb, uintmax_t str_len, int *size)
{
	*size += 1;
	while (nb >= str_len)
	{
		nb /= str_len;
		*size += 1;
	}
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
	get_number_size((uintmax_t)(nb < 0 ? -nb : nb), 10, &size);
	precision = flags->precision - size;
	size = (flags->precision > size) ? flags->precision : size;
	size = (flags->precision == -1 && nb == 0) ? 0 : size;
	size += (nb >= 0 && (flags->plus || flags->space));
	if (nb < 0)
		size++;
	size = display_d(flags, size, precision, nb);
	size = (flags->minus) ? ft_pad(flags, size) : size;
	return (size);
}

uintmax_t	get_number_u(t_flags *flags, va_list args)
{
	uintmax_t    num;

// need to add va_list args to structure
	num = va_arg(args, uintmax_t);
	if (flags->len == LEN_TYPE_HH)
		num = (unsigned char)num;
	else if (flags->len == LEN_TYPE_H)
		num = (unsigned short)num;
	else if (flags->len == LEN_TYPE_LL)
		num = (unsigned long long)num;
	else if (flags->len == LEN_TYPE_L)
		num = (unsigned long)num;
	else if (flags->len == LEN_TYPE_J)
		num = (uintmax_t)num;
	else if (flags->len == LEN_TYPE_Z)
		num = (size_t)num;
	else
		num = (unsigned int)num;
	return (num);
}

int		print_o(t_flags *flags, va_list args)
{
	uintmax_t	nb;
	int			size;
	int			nb_size;

	if (flags->precision != 0)
		flags->zero = 0;
	size = 0;
	nb = get_number_u(flags, args);
	if (flags->precision >= 0 || nb > 0)
		get_number_size(nb , 8, &size);
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

void		display_padding(t_flags *flags, uintmax_t nb, int *size, char *base)
{
	int		width;
	int		prec;

	if (flags->precision <= 0 && flags->width <= 0)
	{
		if (flags->type == 'p' && *size > 0)
			*size += 2;
		return ;
	}
	width = 0;
	prec = flags->precision - *size;
	while (flags->minus && width++ < prec)
		ft_write("0", 1, flags);
	*size = (flags->precision > *size) ? flags->precision : *size;
	if (flags->minus && flags->precision != -1)
		ft_putnbr_maxint_u(nb, base, ft_strlen(base), flags);
	width = 0;
	while (width++ < flags->width - (*size + (flags->type == 'p' ? 2 : 0)))
		ft_write((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
	width = 0;
	while (!flags->minus && width++ < prec)
		ft_write("0", 1, flags);
	if (*size > 0 && flags->type == 'p')
		*size += 2;
}

int		handle_hash(t_flags *flags, uintmax_t nb, int *size, char *hash_key)
{
	int		prec;

	prec = 0;
	if (nb == 0 && flags->type != 'p')
		flags->hash = 0;
	if (flags->hash && (!flags->width || flags->minus || flags->zero ||
			(prec = flags->precision > *size)))
		ft_write(hash_key, (int)ft_strlen(hash_key), flags);
	if (flags->hash && ((flags->width) && !prec) && flags->type != 'p')
		*size += (int)ft_strlen(hash_key);
	return (prec);
}

int		ft_pad_nb(t_flags *flags, va_list args, char *base, char *hash_key)
{
	int			size;
	uintmax_t	nb;
	int			prec;

	if (flags->precision != 0)
		flags->zero = 0;
	size = 0;
	nb = get_number_u(flags, args);
	get_number_size(nb, ft_strlen(base), &size);
	prec = handle_hash(flags, nb, &size, hash_key);
	if (flags->precision == -1 && !nb)
			size = 0;
		display_padding(flags, nb, &size, base);
	if (flags->hash && flags->width && !flags->minus && !flags->zero &&
			!prec)
		ft_write(hash_key, (int)ft_strlen(hash_key), flags);
	if ((!flags->width || !flags->minus) && size > 0)
		ft_putnbr_maxint_u(nb, base, ft_strlen(base), flags);
	if (flags->hash && size > 0 && ((!flags->width || flags->minus) ||
			prec) && flags->type != 'p')
		size += (int)ft_strlen(hash_key);
	if (!size && flags->type == 'p')
		size = 2;
	return (flags->width - size > 0 ? flags->width : size);
}

int		print_x(t_flags *flags, va_list args)
{
	return (ft_pad_nb(flags, args, "0123456789abcdef", "0x"));
}

int		print_x_upper(t_flags *flags, va_list args)
{
	return (ft_pad_nb(flags, args, "0123456789ABCDEF", "0X"));
}