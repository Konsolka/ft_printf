/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:16:46 by mburl             #+#    #+#             */
/*   Updated: 2019/11/29 15:05:05 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "ft_printf.h"



#define PSH(X) (*(buf++)=(X))
#define PSH1(X) (*(buf--)=(X))
#define PEEK() buf[-1]
#define POP() *(--buf) = '\0'

#define PLUS 1
#define SPACE 2



static double	calc_mod(double nb, int *size)
{
	double mod;

	mod = 1;
	nb += 0.5;
	while ((int)(nb /= 10) != 0 && (*size)++)
		mod *= 10;
	return (mod);
}

void reverse(char *str, int len)
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

static int		handle_inf(char **s)
{
	if (!(*s = (char *)malloc(sizeof(char) * 4)))
		return (0);
		*s = "inf";
		return (3);
}

int				ft_gcvt(double nb, char **s, int prec)
{
	int		i;
	int		size;
	char	*str;
	int		neg;
	double	mod;

	if (nb == INFINITY)
		return (handle_inf(s));
	size = 1;
	neg = 0;
	if (nb < 0.0 && size++ && (neg = 1) == 1)
		nb = -nb;
	mod = calc_mod((prec == 0) ? nb + 0.5 : nb, &size);
	size += (prec == 0) ? 0 : prec + 1;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	if (neg)
		str[i++] = '-';
	str[i] = '\0';
	*s = str;
	return (size);
}


int			ft_numlen(double nb)
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

void		ft_pad_float(char **str, int *size, t_flags *flags, int sign)
{
	char	*s;
	char	*temp;
	int		size_temp;
	int		i;

	size_temp = ((flags->width > *size) ? flags->width : *size) + flags->plus + flags->space;
	// printf("---%i   %i", size_temp, *size);
	temp = ft_strnew(size_temp);
	i = 0;
	if ((sign || flags->plus) && flags->zero)
		temp[i++] = (sign == 1) ? '-' : '+';
	else
		flags->width--;
	
	if (flags->minus == 0)
		while (i < flags->width - *size)
			temp[i++] = (flags->zero == 1) ? '0' : ' ';
	if ((sign || flags->plus) && !flags->zero)
		temp[i++] = (sign == 1) ? '-' : '+';
	temp = ft_strcat(temp, *str);
	i = ft_strlen(temp);
	if (flags->minus)
		while (i <= flags->width)
			temp[i++] = ' ';
	*size = ft_strlen(temp);
	*str = ft_strcpy(*str, temp);
	free(temp);
}

int			sv_gcvt(double f, char **s, int prec, t_flags *flags)
{
	int i;
	uintmax_t z, k;
	char *buf;
	double f2, t, scal;
	int sign;
	int j;
	int size;

	j = 0;
	sign = 0;
	if (f < 0.0) {
	    sign = 1;
	    f = -f;
	}
	size = ((flags->plus == 1) ? 1 : sign) +
		((flags->width > ft_numlen(f) + prec) ? flags->width : ft_numlen(f) + prec + 1)
		- ((!flags->precision) ? 1 : 0) + ((flags->hash) ? 1 : 0);
	printf("---%i----", size);
	buf = ft_strnew(size);
	scal = 1.0;
	i = prec;
	while (i-- > 0)
		scal *= 10.0;
	k = f + 0.5 / scal;
	f2 = f - k;
	if (!flags->width)
		while(j <= flags->width - ft_numlen(f) - prec)
			buf[j++] = ' ';
	if (!f)
	{
	    buf[j++] = '0';
	    if (prec > 0 || flags->hash == 1)
	        buf[j++] = '.';
	    for (i = 0; i < prec; i++)
			buf[j++] = '0';
	    buf[size] = 0;
	}
	else 
	{
	    i = 1;
	    if (prec > 0)
		{
	        t = f2 * scal;
	        z = (uintmax_t)(t + 0.5);
	        for (i = 0; i < prec; i++)
			{
	            buf[j++] = '0' + (z % 10);
	            z /= 10;
	        }
	    } // если flags->hash == 1 и пресижн == 0 то надо отобразить точку
		if (flags->hash == 1 || prec > 0)
			buf[j++] = '.';
	    do
		{
			buf[j++] = '0' + (k % 10);
	        k /= 10;
	    } while (k);
	}
	if (flags->zero == 0 && (flags->plus || sign))
		buf[j++] = (sign) ? '-' : '+';
	if (flags->minus == 0)
		while (j <= size - ft_numlen(f) - prec)
			buf[j++] = (flags->zero == 1) ? '0' : ' ';
	reverse(buf, ft_strlen(buf));
	buf[ft_strlen(buf)] = 0;
	*s = buf;
	return (size);
}