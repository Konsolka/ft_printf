/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:02:37 by mburl             #+#    #+#             */
/*   Updated: 2019/11/20 15:38:50 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pad(t_flags *flags, int size)
{
	int		width;

	if (flags->width <= 0)
		return (size);
	width = 0;
	while (width++ < flags->width - size)
		ft_write((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
	return (size + width - 1);
}

int		ft_write(void *s, int size, t_flags *flags)
{
	int		i;
	char	*str;

	if (flags->byte + size > BUFF_SIZE)
	{
		write(1, flags->buff, (size_t)flags->byte);
		flags->byte = 0;
		if (size > BUFF_SIZE)
		{
			write(1, s, (size_t)size);
			return (size);
		}
	}
	i = 0;
	str = s;
	while (i < size)
		flags->buff[flags->byte++] = str[i++];
	flags->byte_total += size;
	return (size);
}

int		write_untill(char **format, t_flags *flags)
{
	int		next;

	if (ft_strchr(*format, '%'))
		next = (int)(ft_strchr(*format, '%') - *format);
	else
		next = (int)ft_strlen(*format);
	ft_write(*format, next, flags);
	*format += next;
	return (next);
}

int		ft_write_char(char c, t_flags *flags)
{
	return (ft_write(&c, 1, flags));
}
