/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:26:39 by abenton           #+#    #+#             */
/*   Updated: 2019/11/15 15:04:25 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_s(t_flags	*flags, va_list args)
{
	char	*s;
	int		i;
	int		len;

	s = va_arg(args, char *);
	if (flags->len == LEN_TYPE_L)
		s = (wchar_t *)s;
	else
		s = (char *)s;
	if (flags->precision > 0 && s)
		s = strndup(flags->precision, s);	//FT_STRDUP
	else if (flags->precision == 0 && s)
		s = ft_strdup(s);
	else if (flags->precision > 0 && !s)
		s = strndup("(null)", flags->precision); // FT_STRDUP
	else if (flags->precision == 0 && !s)
		s = ft_strdup("(null)");
	len = ft_strlen(s);
	flags->len += len;
	ft_write(s, (int)ft_strlen(s), flags);
	return (0);
}
