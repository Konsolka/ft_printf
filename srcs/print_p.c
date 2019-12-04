/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:05:02 by mburl             #+#    #+#             */
/*   Updated: 2019/12/04 11:56:01 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_p(t_flags *flags, va_list args)
{
	flags->length = LEN_TYPE_L;
	flags->hash = 1;
	return (print_x(flags, args));
}
