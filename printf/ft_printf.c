#include "ft_printf.h"

void	ft_check(t_read	*list, char *str, int len)
{
	int	check;
	
	len++;
	if (str[len] == 'c')
		ft_putchar(list, va_arg(list->args, int));
	else if (str[len] == 's')
		ft_putstr(list, va_arg(list->args, char *));
	else if (str[len] == 'p' || str[len] == 'x' || str[len] == 'X')
	{
		if (str[len] == 'p')
			check = 1;
		ft_puthex(list, va_arg(list->args, unsigned long), str[len], check);
	}
	else if (str[len] == 'd' || str[len] == 'i')
		ft_putnbr(list, va_arg(list->args, int));
	else if (str[len] == 'u')
		ft_putunbr(list, va_arg(list->args, unsigned int));
	else
	{
		ft_putchar(list, str[len]);
		list->count += 1;
	}
}

static t_read	*ft_arg_dec(void)
{
	t_read *list;

	list = (t_read *) malloc(sizeof(t_read));
	if (list == NULL)
		return (NULL);
	list->count = 0;
	return (list);
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
			list->count += 1;
		}
		else if (str[len] == '%')
		{
			ft_check(list, str, len);
			len++;
		}
		len++;
	}
	va_end(list->args);
	len = list->count;
	return (len);
}
