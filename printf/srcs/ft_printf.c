/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwhitfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:55:04 by rwhitfor          #+#    #+#             */
/*   Updated: 2021/10/19 13:55:04 by rwhitfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(t_read	*list, const char *str, int len)
{
	len++;
	if (str[len] == 'c')
		ft_putchar(list, va_arg(list->args, int));
	else if (str[len] == 's')
		ft_putstr(list, va_arg(list->args, char *));
	else if (str[len] == 'x' || str[len] == 'X')
		ft_puthex(list, va_arg(list->args, unsigned int), str[len]);
	else if (str[len] == 'p')
		ft_putptr(list, va_arg(list->args, unsigned long));
	else if (str[len] == 'd' || str[len] == 'i')
		ft_putnbr(list, va_arg(list->args, int));
	else if (str[len] == 'u')
		ft_putunbr(list, va_arg(list->args, unsigned int));
	else
		ft_putchar(list, str[len]);
}

static t_read	*ft_arg_dec(void)
{
	t_read	*list;

	list = (t_read *)malloc(sizeof(t_read));
	if (list == NULL)
		return (NULL);
	list->count = 0;
	return (list);
}

int	ft_printf(const	char *str, ...)
{
	t_read	*list;
	int		len;

	list = ft_arg_dec();
	if (list == NULL)
		return (-1);
	len = 0;
	va_start(list->args, str);
	while (str[len] != '\0')
	{
		if (str[len] != '%')
		{
			ft_putchar(list, str[len]);
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
	free(list);
	return (len);
}
