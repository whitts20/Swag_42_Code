static t_read	*ft_arg_dec(void)
{
	t_read *list;

	list = (t_read *) malloc(sizeof(t_read));
	if (list == NULL)
		return (NULL);
	list->count = 0;
	return (table);
}

int	ft_printf(const char *str, ...)
{
	t_read *list;
	int		len;

	list = ft_arg_dec();
	if (list == NULL)
		return (-1);
	va_start(list->args, str);
	while (str[len] != '\0')
	{
		if (str[len] != '%')
		{
			ft_putchar_fd(*str, 1);
			list->count++;
		}
		else if (str[len] == '%')
		{
			ft_check(list, str);
			len++;
		}
		len++;
	}
	va_end(list->args)
	len = list->count;
	return (len);
}
