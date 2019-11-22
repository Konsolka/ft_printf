/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:16:46 by mburl             #+#    #+#             */
/*   Updated: 2019/11/22 16:51:44 by mburl            ###   ########.fr       */
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
	handle_int(&nb, &str, &i, mod);
	handle_dec(&str, &i, nb, prec);
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


int			sv_gcvt(double f, char **s, int prec)
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
	size = sign + ft_numlen(f) + 1 + prec;
	buf = ft_strnew(size);
	scal = 1.0;
	i = prec;
	while (i-- > 0)
		scal *= 10.0;
	k = f + 0.5 / scal;
	f2 = f - k;
	if (!f)
	{
	    buf[j++] = '0';
	    if (prec > 0)
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
			buf[j++] = '.';
	    } // если flags->hash == 1 и пресижн == 0 то надо отобразить точку
	    do
		{
			buf[j++] = '0' + (k % 10);
	        k /= 10;
	    } while (k);
	}
	if (sign)
		buf[j++] = '-';
	reverse(buf, ft_strlen(buf));
	*s = buf;
	return (ft_strlen(buf));
}