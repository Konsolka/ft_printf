/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:07:13 by mburl             #+#    #+#             */
/*   Updated: 2019/12/04 12:09:12 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <float.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

int				main(void)
{
	printf("%5x#\n", 52625);
	ft_printf("%5x#", 52625);
	return (0);
}
