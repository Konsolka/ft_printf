/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:37:38 by mburl             #+#    #+#             */
/*   Updated: 2019/11/14 14:55:43 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>

# define BUFF_SIZE 64
# define ARGS 22

typedef struct	s_flags
{
	int		hash;
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		width;
	int		precision;
	char	*len;
	char	type;
	char	buff[BUFF_SIZE];
	int		byte;
	int		byte_total;
}				t_flags;

typedef struct	s_type
{
	char	name;
	int		(*f)();
}				t_type;

int		ft_pad(t_flags *flags, int size);
int		ft_write(void *s, int size, t_flags *flags);
int		write_untill(char **format, t_flags *flags);
int		call_type(char **str, va_list args, t_flags *flags);
void	init_flags(t_flags *flags);
int		handle_flags(char **str, t_flags *flags);
int		handle_width(char **str, t_flags *flags, va_list args);
int		handle_precision(char **str, t_flags *flags, va_list args);
int		handle_length(char **str_c, t_flags *flags);


int		print_d(t_flags *flags, va_list args);
#endif