#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>

# define BUFF_SIZE 64
# define ARGS 22

# define LEN_TYPE_H 0
# define LEN_TYPE_L_LAR 1
# define LEN_TYPE_J 2
# define LEN_TYPE_L 3
# define LEN_TYPE_Z 4
# define LEN_TYPE_LL 5
# define LEN_TYPE_HH 6

typedef struct	s_printf
{
    va_list args;
	int		return_value; // return value of ft_printf.c
    int		hash; // #
	int		zero; // 0
	int		minus; // -
	int		plus; // +
	int		space; // ' '
    int		width;
	int		precision;
	int     lenght;
    char	type;
	char	buff[BUFF_SIZE];
	int		byte;
	int		byte_total;
}				t_printf;

int		ft_printf(const char * restrict format, ...);


#endif