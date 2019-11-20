/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenton <abenton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:26:39 by abenton           #+#    #+#             */
/*   Updated: 2019/11/20 17:25:54 by abenton          ###   ########.fr       */
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
	int		width;

	s = va_arg(args, char *);
	if (!s)
		s = ft_strdup("(null)");
	len = (int)ft_strlen(s);
	len = (flags->precision == -1) ? 0 : len;
	if (flags->precision > 0 && flags->precision < len && len > 0)
		len = flags->precision;
	if (flags->width)
	{
		if (flags->minus)
			ft_write(s, len, flags);
		width = 0;
		while (width++ < flags->width - len)
			ft_write((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
	}
	if (!flags->width || !flags->minus)
		ft_write((s) ? s : "(null)", len, flags);
	return (len + (flags->width - len > 0 ? flags->width - len : 0));
}
