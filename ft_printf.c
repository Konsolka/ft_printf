/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:49:30 by mburl             #+#    #+#             */
/*   Updated: 2019/10/25 12:48:17 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

/*
**	trying to write % parcer to the t_holder struct
**	should somehow parce string for example -lld to fields in t_holder fields
*/
t_holder		*parse_field(char *str)
{
	t_holder	*fields;
	t_flags		*flags;
	t_length	*length;
	int 	i;

	ft_set_flags_to_zero(&flags);
	ft_set_len_to_zero(&length);
	i = 0;
	if (str[ft_strlen(str) - 1] == '%')
	{
		ft_putchar('%');
		return (NULL);
	}
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == ' ' ||
		str[i] == '0' || str[i] == '#')
			ft_handle_flags(str[i], flags);
		if (str[i] == 'h' || str[i] == 'l' || str[i] == 'L' || str[i] == 'z' ||
		str[i] == 'j' || str[i] == 't')
			ft_handle_length(&str[i], length);
		i++;
	}
	fields = (t_holder *)malloc(sizeof(t_holder));
	fields->flag = flags;
	fields->length = length;
	fields->type = str[i - 1];
	return (fields);
}

/*
**	gets what is going after %
**	example: ft_printf("kek%-lldsi"); will get -lld
*/
char	*handle_format(const char * restrict str, int *i)
{
	char	*format;
	int		temp;
	int		i_temp;

	i_temp = *i + 1;
	temp = i_temp;
	while (str[i_temp] != 'd' && str[i_temp] != 'i' && str[i_temp] != 'u' && str[i_temp] != 'f' &&
		str[i_temp] != 'F' && str[i_temp] != 'e' && str[i_temp] != 'E' && str[i_temp] != 'g' &&
		str[i_temp] != 'G' && str[i_temp] != 'x' && str[i_temp] != 'X' && str[i_temp] != 'o' &&
		str[i_temp] != 's' && str[i_temp] != 'c' && str[i_temp] != 'p' && str[i_temp] != 'a' &&
		str[i_temp] != 'A' && str[i_temp] != 'n' && str[i_temp] != '%')
		i_temp++;
	i_temp++;
	format = (char *)malloc(sizeof(char) * (i_temp - temp));
	format = ft_strsub(str, temp, i_temp - temp);
	*i = i_temp;
	return (format);
}

/*
**	printf
*/
int		ft_printf(const char * restrict format, ...)
{
	int		i;
	char	*field;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i++]);
		else
		{
			field = handle_format(format, &i);
			parse_field(field); // c konca
		}
	}
	ft_putchar('\n');
	ft_putstr(field);
	return (0);
}