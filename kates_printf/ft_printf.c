
int		ft_printf(const char * restrict format, ...)
{
    t_prinf	*str;

    if (!(str = (t_tab*)malloc(sizeof(t_printf))))
		return (-1);
    if (format)
    {
        va_start(args, format);
        str->return_value = parser(str);
        va_end(args, format);
    }
    free(str);
	return (return_value);
}