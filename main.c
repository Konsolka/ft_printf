/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:07:13 by mburl             #+#    #+#             */
/*   Updated: 2019/10/22 11:27:28 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int		ft_printf(const char * restrict format, ...);

int		main(void)
{
	printf("%d\n", 5);
	ft_printf("%d\n");
	return (0);
}

