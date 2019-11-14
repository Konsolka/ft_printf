/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:49:30 by mburl             #+#    #+#             */
/*   Updated: 2019/11/14 16:50:58 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	g_type[ARGS] = {
	{'i', print_d}
	// {'c', print_c}, {'C', print_c_upper}, {'d', print_d}, {'D', print_d_upper},
	// {'i', print_i}, {'o', print_o}, {'u', print_u}, {'x', print_x},
	// {'X', print_x_upper}, {'e', print_e}, {'E', print_e_upper}, {'f', print_f},
	// {'F', print_f_upper}, {'g', print_g}, {'G', print_g_upper}, {'a', print_a},
	// {'A', print_a_upper}, {'n', print_n}, {'p', print_p}, {'s', print_s},
	// {'S', print_s_upper}, {'Z', print_z_upper}
};

static int		handle(char **str, va_list args, t_flags *flags)
{
	int		flags_found;

	init_flags(flags);
	while (**str)
	{
		flags_found = 0;
		while (handle_length(str, flags) ||
				handle_flags(str, flags) ||
				handle_width(str, flags, args) ||
				handle_precision(str, flags, args))
			flags_found = 1;
		if (ft_isalpha(**str) || **str == '%')
			return (call_type(str, args, flags));
		else if (!*(*str + 1) || !flags_found)
			return (0);
	}
	return (0);
}

int		call_type(char **str, va_list args, t_flags *flags)
{
	int		arg;
	int		size;

	arg = 0;
	while (arg < ARGS)
	{
		if (**str == g_type[arg].name)
		{
			*str += 1;
			flags->type = g_type[arg].name;
			return (g_type[arg].f(flags, args));
		}
		arg++;
	}
	size = 1;
	if (!flags->minus)
		size = ft_pad(flags, size);
	ft_write(*str, 1, flags);
	if (flags->minus)
		size = ft_pad(flags, size);
	*str += 1;
	return (size);
}

/*
**	printf
*/

int		ft_printf(const char * restrict format, ...)
{
	t_flags flags;
	va_list	args;
	char	*str;
	int		bytes;

	bytes = 0;
	flags.byte = 0;
	flags.byte_total = 0;
	va_start(args, format);
	str = (char *)format;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			bytes += handle(&str, args, &flags);
		}
		else
			bytes += write_untill(&str, &flags);
	}
	va_end(args);
	if (flags.byte > 0)
		write(1, flags.buff, (size_t)flags.byte);
	return (bytes);
}