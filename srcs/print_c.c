/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:49:01 by abenton           #+#    #+#             */
/*   Updated: 2019/12/04 11:53:42 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_c(t_flags *flags, va_list args)
{
	int		c;
	int		width;

	width = 0;
	c = (char)va_arg(args, int);
	if (flags->width)
	{
		if (flags->minus)
			ft_write(&c, 1, flags);
		while (width++ < flags->width - 1)
			ft_write((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
	}
	if (!flags->width || !flags->minus)
		ft_write(&c, 1, flags);
	if (flags->width)
		return (width);
	else
		return (1);
}
