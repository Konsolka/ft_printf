t_printf    *reinitialize(t_printf *str)
{

    return (str);
}

t_printf	*parse_flags(t_printf *str)
{
	size_t	i;

	i = 0;
	while (str->flags_all[i] != '\0')
	{
		while (str->flags_all[i] == str->copy[str->i])
		{
			while (str->copy[str->i] == '-' && str->i++)
				str->flags[0] = '-';
			while (str->copy[str->i] == '+' && str->i++)
				str->flags[1] = '+';
			while (str->copy[str->i] == ' ' && str->i++)
				str->flags[2] = ' ';
			while (str->copy[str->i] == '0' && str->i++)
				str->flags[3] = '0';
			while (str->copy[str->i] == '#' && str->i++)
				str->flags[4] = '#';
			i = 0;
		}
		i++;
	}
	return (str);
}

t_printf	*parse_width(t_printf *str)
{
	while (str->copy[str->i] >= '0' && str->copy[str->i] <= '9')
	{
		str->width *= 10;
		str->width += (str->copy[str->i] - 48);
		str->i++;
	}
	return (str);
}

t_printf    *parse_length(t_printf *str)
{
    /* kek */
    return (str);
}

t_printf	*parse_type(t_printf *str)
{
	size_t	i;

	i = 0;
	while (str->type_all[i] != '\0')
	{
		if (str->type_all[i] == str->copy[str->i])
			str->type = str->type_all[i];
		i++;
	}
	return (str);
}

t_printf	*choose_type(t_printf *str)
{
	char	*flag;

	/* flag = & */
	if (*flag == 'd' || *flag == 'i')
		print_d(str);
	else if (*flag == 'c')
		print_c(str);
	else if (*flag == 's')
		print_s(str);
	else if (*flag == 'u')
		print_u(str);
	else if (*flag == 'x' || *flag == 'X')
		print_x(str);
	else if (*flag == 'o')
		print_o(str);
	else if (*flag == 'p')
		print_p(str);
	else
		print_else(tab);
	return (str);
}

int         parser(t_printf *str)
{
    size_t i;

    if (ft_strcmp(str->copy, "%") == 0)
		return (0);
    i = 0;
    while (str->copy[i] != '\0')
    {
        if (stsr->copy == '%')
        {
            reinitialize(str);
            parse_flags(str);
            parse_width(str);
            parse_precision(str);
            parse_length(str);
            parse_type(str);
            choose_type(str);
        }
        else
        {
            write(1, &str->copy[i], 1);
            str->return_value++;
        }
        i++;
    }
    return (return_value);
}