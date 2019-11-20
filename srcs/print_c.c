/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:02:04 by abenton           #+#    #+#             */
/*   Updated: 2019/11/19 12:46:43 by abenton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_c(t_flags *flags, va_list args)
{
	wint_t	c;
	
	if (flags->len == LEN_TYPE_L)
		c = (unsigned long)va_arg(args, unsigned long);
/*
 * Обработка большой буквы!
 	else if ()
		c = (wchar_t)va_arg(tab->args, wint_t);
*/
	else
		c = (char)va_arg(args, int);
	if (flags->zero && !flags->minus)
		kek;
	else if (!flags->minus)
		kek1;
	ft_write();
	if(flags->minus)
		kek2;
	return (1 + (flags->width - 1 > 0 ? flags->width - 1 : 0));
}
