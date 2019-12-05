/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:07:13 by mburl             #+#    #+#             */
/*   Updated: 2019/12/05 10:02:37 by mburl            ###   ########.fr       */
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
	ft_printf("%zhd", 4294967296);
	printf("%zhd", 4294967296);
	return (0);
}
