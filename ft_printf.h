/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:37:38 by mburl             #+#    #+#             */
/*   Updated: 2019/10/25 12:46:09 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H


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