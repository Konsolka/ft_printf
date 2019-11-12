/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:02:37 by mburl             #+#    #+#             */
/*   Updated: 2019/10/25 12:44:49 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void    ft_set_flags_to_zero(t_flags **flags)
{
	t_flags	*node;

	node = (t_flags *)malloc(sizeof(t_flags));
	node->minus = 0;
	node->plus = 0;
	node->hash = 0;
	node->zero = 0;
	node->space = 0;
	*flags = node;
}

void	ft_set_len_to_zero(t_length **len)
{
	t_length *node;

	node = (t_length *)malloc(sizeof(t_length));
	node->h = 0;
	node->hh = 0;
	node->j = 0;
	node->L = 0;
	node->l = 0;
	node->ll = 0;
	node->t = 0;
	node->z = 0;
	*len = node;
}
void    ft_handle_flags(char c, t_flags *flags)
{
	if (c == '-')
		flags->minus = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '0')
		flags->zero = 1;
	else if (c == '#')
		flags->hash = 1;
}

void	ft_handle_length(char *str, t_length *len)
{
	if (str[0] == 'h' && str[1] == 'h')
		len->hh = 1;
	if (str[0] == 'h' && str[1] != 'h' && str[-1] != 'h')
		len->h = 1;
	if (str[0] == 'l' && str[1] == 'l')
		len->ll = 1;
	if (str[0] == 'l' && str[1] != 'l' && str[-1] != 'l')
		len->l = 1;
	if (str[0] == 'L')
		len->L = 1;
	if (str[0] == 't')
		len->t = 1;
	if (str[0] == 'z')
		len->z = 1;
}