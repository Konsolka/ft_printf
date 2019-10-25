/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:08:17 by abenton           #+#    #+#             */
/*   Updated: 2019/10/23 18:22:38 by abenton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Sets every flag to zero
 */

void	ft_set_flags_to_zero(t_flags *flags)
{	
	flags->precision = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->hashh = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->width = 0;
	flags->lengthh = 0;
}

/*
 * Fills the structure and increment the string
 */

void	ft_handle_flags(char **str, t_flags *flags)
{
	if (*(*str) == '-')
		flags->minus = 1;
	else if (*(*str) == '+')
		flags->plus = 1;
	else if (*(*str) == ' ')
		flags->space = 1;
	else if (*(*str) == '0')
		flags->zero = 1;
	else if (*(*str) == '#')
		flags->hashh = 1;
}

int		parse(char *format, t_flags *mem)
{
	char *s;

	while (*s)
	{
		
	}
}

int     kek(int fd, char *format, va_list args, int nbr)
{
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			nbr++;
		}
		else if (*format == '%' && *(format + 1) == '%')
		{
			ft_putchar(*format);
			nbr++;
		}
		else if (*format == '%')
		{
			format++;
			nbr = ft_parse();
		}
	}
	return (nbr);
}
