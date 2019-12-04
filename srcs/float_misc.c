/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:23:25 by mburl             #+#    #+#             */
/*   Updated: 2019/12/04 14:28:43 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_sign_float(long double nb, t_flags *flags)
{
	if (nb < 0.0)
		ft_write("-", 1, flags);
	if (flags->plus && nb >= 0.0)
		ft_write("+", 1, flags);
	else if (flags->space && nb >= 0.0)
		ft_write(" ", 1, flags);
}

int		ft_numlen(long double nb)
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

void	reverse(char *str, int len)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}
