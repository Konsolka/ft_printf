/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:16:46 by mburl             #+#    #+#             */
/*   Updated: 2019/11/21 18:29:08 by mburl            ###   ########.fr       */
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
	unsigned long long	z;
	double				scal;
	int		 			iterartor;
	char				*s;
	char				*buf;

	if (prec == 0)
		return ;
	if (!(buf = (char *)malloc(sizeof(char) * prec + 1)))
		return ;
	s = *str;
  	if (prec > 20)
		prec = 20;
	scal = 1;
	iterartor = prec;
	while (iterartor-- > 0)
		scal *= 10;
	z = nb * scal + 0.5;
	iterartor = 0;
	while (iterartor < prec)
	{
		buf[iterartor] = '0' + (z % 10);
		z /= 10;
		iterartor++;
	}
	buf[iterartor] = '.';
	reverse(buf, (int)ft_strlen(buf));
	iterartor = 0;
	while (buf[iterartor])
	{
		s[(*i)++] = buf[iterartor++];
	}
	free(buf);
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
	printf("== %s == ", str);
	str[i] = '\0';
	printf("== %s == ", str);
	*s = str;
	return (size);
}
