/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:56:42 by mburl             #+#    #+#             */
/*   Updated: 2019/11/13 14:15:46 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->precision = 0;
	flags->buff = 0;
	flags->byte = 0;
	flags->byte_total = 0;
	flags->hash = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->precision = 0;
	flags->space = 0;
	flags->type = 0;
	flags->len_type = ft_strnew(3);
}