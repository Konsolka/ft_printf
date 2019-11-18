/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:26:39 by abenton           #+#    #+#             */
/*   Updated: 2019/11/18 15:54:48 by abenton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!(s2 = ft_strnew(n)))
		return (NULL);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

int		print_s(t_flags	*flags, va_list args)
{
	char	*s;
	int		len;

	len = 0;
	if (args == NULL || flags->precision == -1)
		return (0);
	s = va_arg(args, char *);
	if (flags->precision > 0 && s)
		s = ft_strndup(s, flags->precision);
	else if (flags->precision == 0 && s)
		s = ft_strdup(s);
	else if (!s && flags->precision > 0)
	{
		if (flags->precision > 6)
			s = ft_strdup("(null)");
		else
			s = ft_strndup("(null)", flags->precision);
	}
	else if ((flags->precision == 0 || flags->precision == -1) && !s)
		s = ft_strdup("(null)");
	else if (!flags->precision && !s)
		s = ft_strdup("");
	if (flags->width > 0 && flags->precision == -1 && !s)
		len += ft_pad(flags, len);
	len += ft_strlen(s);
	if (flags->width > 0 && !flags->minus)
		len += ft_pad(flags, len);
	ft_write(s, (int)ft_strlen(s), flags);
	if (flags->width > 0 && flags->minus)
		len += ft_pad(flags, len);
	return (len);
}
