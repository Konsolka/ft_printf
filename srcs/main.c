/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenton <abenton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:07:13 by mburl             #+#    #+#             */
/*   Updated: 2019/12/04 17:25:25 by abenton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"
#include <float.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

int				main(void)
{
	ft_printf("%b", 42);
	return (0);
}
