/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_filed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:22:22 by mburl             #+#    #+#             */
/*   Updated: 2019/11/14 16:51:04 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_flags(char **str, t_flags *flags)
{
	if (*(*str) == '-')
		flags->minus = 1;
	else if (*(*str) == '+')
		flags->plus = 1;
	else if (*(*str) == '0')
		flags->zero = 1;
	else if (*(*str) == '#')
		flags->hash = 1;
	else if (*(*str) == ' ')
		flags->space = 1;
	else
		return (0);
	(*str)++;
	return (1);
}

int		handle_width(char **str, t_flags *flags, va_list args) // incorrect
{
	int		width;

	if ((width = ft_atoi(*str)) > 0 || **str == '*')
	{
		if (**str == '*')
		{
			width = va_arg(args, int);
			if (width < 0)
				flags->minus = 1;
			flags->width = (width < 0 ? width * -1 : width);
			width = 1;
		}
		else
			flags->width = width;
		while (width > 0 && (*str += 1))
		{
			width /= 10;
		}
		return (1);
	}
	return (0);
}

int		handle_precision(char **str, t_flags *flags, va_list args)
{
	int		precision;

	if (**str == '.')
	{
		*str += 1;
		if (!ft_isdigit(**str) && **str != '*')
		{
			flags->precision = 1;
			return (1);
		}
		precision = (**str == '*') ? va_arg(args, int) : ft_atoi(*str);
		flags->precision = (precision == 0 ? -1 : precision);
		if (flags->precision < 0 && flags->precision != -1)
			flags->precision = 0;
		if (**str == '*')
			precision = 1;
		else if (precision == 0)
			*str += 1;
		while (precision > 0 && *(++str))
			precision /= 10;
		return (1);
	}
	return (0);
}

void	edit_len_type(int len_type, t_flags *flags, char **str)
{
	flags->len = len_type;
	if (len_type > 4)
		*str += 1;
	*str += 1;
}
int		handle_length(char **str_c, t_flags *flags)
{
	char *str;

	str = *str_c;
	if (str[0] == 'h' && str[1] == 'h')
		edit_len_type(LEN_TYPE_HH, flags, str_c);
	else if (str[0] == 'h')
		edit_len_type(LEN_TYPE_H, flags, str_c);
	else if (str[0] == 'l' && str[1] == 'l')
		edit_len_type(LEN_TYPE_LL, flags, str_c);
	else if (str[0] == 'l')
		edit_len_type(LEN_TYPE_L, flags, str_c);
	else if (str[0] == 'L')
		edit_len_type(LEN_TYPE_L_LAR, flags, str_c);
	else if (str[0] == 't')
		edit_len_type(LEN_TYPE_J, flags, str_c);
	else if (str[0] == 'z')
		edit_len_type(LEN_TYPE_Z, flags, str_c);
	else
		return (0);
	return (1);
}