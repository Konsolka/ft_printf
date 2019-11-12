/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:37:38 by mburl             #+#    #+#             */
/*   Updated: 2019/11/12 17:30:22 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>

# define BUFF_SIZE 64

typedef struct s_printf
{
	int			len;
	short		f;
	short		n;
	int			min_len;
	int			precision;
	int			padding;
	int			printed;
	int			fd;
	int			buff_index;
	char		buff[BUFF_SIZE];
	va_list		ap;
	char		*format;
	unsigned	c;
	
}				t_printf;







typedef struct	s_flags
{
    int		zero;
    int		minus;
    int		plus;
    int		space;
    int		hash;
}				t_flags;

typedef struct	s_length
{
	int		hh;
	int		h;
	int		l;
	int		ll;
	int		L;
	int		z;
	int		j;
	int		t;
}				t_length;

typedef struct	s_holder
{
	t_flags		*flag;
	char		*param;
	char		*width;
	char		*precision;
	t_length	*length;
	char		type;
}				t_holder;

void    ft_set_flags_to_zero(t_flags **flags);
void	ft_set_len_to_zero(t_length **len);
void    ft_handle_flags(char c, t_flags *flags);
void	ft_handle_length(char *str, t_length *len);

#endif