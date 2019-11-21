/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:16:46 by mburl             #+#    #+#             */
/*   Updated: 2019/11/21 15:06:03 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "ft_printf.h"

static double	calc_mod(double nb, int *size)
{
	double mod;

	mod = 1;
	while ((int)(nb /= 10) != 0 && (*size)++)
		mod *= 10;
	return (mod);
}

static void		handle_int(double *nb, char **str, int *i, double mod)
{
	char	*s;

	s = *str;
	if ((int)*nb == 0)
	{
		s[(*i)++] = (char)((*nb / mod) + 48);
		mod /= 10;
	}
	while ((int)*nb != 0)
	{
		s[(*i)++] = (char)((*nb / mod) + 48);
		*nb -= (int)(*nb / mod) * mod;
		mod /= 10;
	}
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

static void		handle_dec(char **str, int *i, double nb, int prec)
{
	int		j;
	unsigned long long scale;
	unsigned long long		temp;
	char	*s;
	

	nb *= 10;
	j = 0;
	s = *str;
	s[(*i)++] = '.';
	while (j++ < prec)
	{
		temp = ((int)nb != 9) ? (int)(nb + 0.01) : (int)nb;
		s[(*i)++] = '0' + temp;
		nb = (nb - temp) * 10;
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
	if (nb < 0 && size++ && (neg = 1) == 1)
		nb = -nb;
	mod = calc_mod(nb, &size);
	size += prec;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	if (neg)
		str[i++] = '-';
	handle_int(&nb, &str, &i, mod);
	handle_dec(&str, &i, nb, prec);
	str[--i] = '\0';
	*s = str;
	return (size);
}