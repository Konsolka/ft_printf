/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:37:38 by mburl             #+#    #+#             */
/*   Updated: 2019/10/22 12:06:02 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_holder
{
	char	*param;
	char	flag;
	char	*width;
	char	*precision;
	char	length[2];
	char	type;
}				t_holder;

#endif