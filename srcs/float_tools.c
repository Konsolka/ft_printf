/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:16:46 by mburl             #+#    #+#             */
/*   Updated: 2019/12/02 15:53:07 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "ft_printf.h"

static void reverse(char *str, int len)
{
	int i=0, j=len-1, temp;
	while (i<j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++; j--;
	}
}

static int		handle_inf(t_flags *flags)
{
	ft_write(((flags->type == 'f') ? "inf" : "INF"), 3, flags);
		return (3);
}

int			ft_numlen(long double nb)
{
	int			i;
	uintmax_t	newnb;

	i = 0;
	newnb = (uintmax_t)nb;
	if (newnb == 0)
		return (1);
	while (newnb > 0)
	{
		newnb /= 10;
		i++;
	}
	return (i);
}
void	display_sign_float(long double nb, t_flags *flags)
{
	if (nb < 0.0)
		ft_write("-", 1, flags);
	if (flags->plus && nb >= 0.0)
		ft_write("+", 1, flags);
	else if (flags->space && nb >= 0.0)
		ft_write(" ", 1, flags);
}

int		ft_pad_float(char *str, int size, t_flags *flags, long double nb)
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
	if (size > 0) //&& ((flags->width || flags->precision)  && !flags->plus && nb) not and may be xor
		ft_write(str, ft_strlen(str), flags);
	return (size + width_size);
}

int			ft_gcvt(long double f, char **s, t_flags *flags)
{
	int i;
	uintmax_t z, k;
	char *buf;
	long double f2, t, scal;
	int sign;
	int j;
	int size;

	if (f == INFINITY)
		return (handle_inf(flags));
	j = 0;
	sign = 0;
	if (f < 0.0) {
	    sign = 1;
	    f = -f;
	}
	size = ft_numlen(f) + flags->precision + 1 - ((flags->precision || flags->hash) ? 0 : 1) +
		((sign) ? 1 : 0) + (!sign && (flags->plus || flags->space));
	buf = ft_strnew(size);
	scal = 1.0;
	i = flags->precision;
	while (i-- > 0)
		scal *= 10.0;
	k = f + 0.5 / scal;
	f2 = f - k;
	if (!f)
	{
	    buf[j++] = '0';
	    if (flags->precision > 0 || flags->hash == 1)
	        buf[j++] = '.';
	    for (i = 0; i < flags->precision; i++)
			buf[j++] = '0';
	    buf[size] = 0;
	}
	else 
	{
	    i = 1;
	    if (flags->precision > 0)
		{
	        t = f2 * scal;
	        z = (uintmax_t)(t + 0.5);
	        for (i = 0; i < flags->precision; i++)
			{
	            buf[j++] = '0' + (z % 10);
	            z /= 10;
	        }
	    } // если flags->hash == 1 и пресижн == 0 то надо отобразить точку
		if (flags->hash == 1 || flags->precision > 0)
			buf[j++] = '.';
	    do
		{
			buf[j++] = '0' + (k % 10);
	        k /= 10;
	    } while (k);
	}
	reverse(buf, ft_strlen(buf));
	// printf("--size = %i--", ft_numlen(f) + flags->precision + 1 - ((flags->precision) ? 0 : 1));
	size = ft_pad_float(buf, size, flags, ((sign) ? -f : f));
	
	size = (flags->minus) ? ft_pad(flags, size) : size;
	*s = buf;
	return (size);
}