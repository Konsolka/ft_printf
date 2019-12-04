/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:16:46 by mburl             #+#    #+#             */
/*   Updated: 2019/12/04 14:28:02 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "ft_printf.h"

static int		ft_pad_float(char *str, int size,
							t_flags *flags, long double nb)
{
	int		width_size;
	int		width;

	width = 0;
	width_size = 0;
	if (!flags->minus)
	{
		if (flags->width && flags->zero)
			display_sign_float(nb, flags);
		width_size = ft_pad(flags, size) - size;
	}
	if ((flags->width && (flags->minus || !flags->zero)) || !flags->width)
		display_sign_float(nb, flags);
	if (size > 0)
		ft_write(str, ft_strlen(str), flags);
	return (size + width_size);
}

static void		float_nul(char *buf, t_flags *flags, int j, int size)
{
	int i;

	i = 0;
	while (i++ < flags->precision)
		buf[j++] = '0';
	if (flags->precision > 0 || flags->hash == 1)
		buf[j++] = '.';
	buf[j++] = '0';
	buf[size] = 0;
}

static void		get_num_float(char *buf, uintmax_t k, int j)
{
	while (k + 1)
	{
		buf[j++] = '0' + (k % 10);
		k /= 10;
		if (k == 0)
			break ;
	}
}

void			float_not_null(char *buf, long double f, t_flags *flags, int j)
{
	int			i;
	uintmax_t	z;
	uintmax_t	k;
	long double	scal;

	scal = ft_pow(10.0, flags->precision);
	k = f + 0.5 / scal;
	if (flags->precision > 0)
	{
		z = (uintmax_t)((f - k) * scal + 0.5);
		i = 0;
		while (i++ < flags->precision)
		{
			buf[j++] = '0' + (z % 10);
			z /= 10;
		}
	}
	if (flags->hash == 1 || flags->precision > 0)
		buf[j++] = '.';
	get_num_float(buf, k, j);
}

int				ft_gcvt(long double f, char **s, t_flags *flags)
{
	char	*buf;
	int		sign;
	int		j;
	int		size;

	j = 0;
	sign = (f < 0.0) ? 1 : 0;
	f = (f < 0.0) ? -f : f;
	size = ft_numlen(f) + flags->precision + 1 -
		((flags->precision || flags->hash) ? 0 : 1) +
		((sign) ? 1 : 0) + (!sign && (flags->plus || flags->space));
	buf = ft_strnew(size);
	if (!f)
		float_nul(buf, flags, j, size);
	else
		float_not_null(buf, f, flags, j);
	reverse(buf, ft_strlen(buf));
	size = ft_pad_float(buf, size, flags, ((sign) ? -f : f));
	size = (flags->minus) ? ft_pad(flags, size) : size;
	*s = buf;
	return (size);
}
