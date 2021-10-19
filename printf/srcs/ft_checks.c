/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwhitfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:55:03 by rwhitfor          #+#    #+#             */
/*   Updated: 2021/10/19 13:55:03 by rwhitfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(t_read	*list, char c)
{
	write(1, &c, 1);
	list->count += 1;
}

void	ft_putstr(t_read	*list, char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		list->count += 6;
		return ;
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
		list->count += 1;
	}
}

void	ft_putnbr(t_read	*list, int n)
{
	unsigned int	var;

	if (n < 0)
	{
		ft_putchar(list, '-');
		list->count += 1;
		var = -n;
	}
	else
	{
		var = n;
	}
	if (var >= 10)
	{
		ft_putnbr(list, (var / 10));
	}
	ft_putchar(list, (var % 10 + 48));
}

void	ft_putunbr(t_read	*list, unsigned int n)
{
	if (n >= 10)
	{
		ft_putunbr(list, (n / 10));
	}
	ft_putchar(list, (n % 10 + 48));
}

void	ft_puthex(t_read	*list, unsigned long n, char c, int check)
{
	char	*str;
	int		i;

	i = 1;
	str = ft_hexstr(n, &i);
	if (check == 1)
		ft_putstr(list, "0x");
	i--;
	while (i >= 0)
	{
		if (n % 16 < 10)
			str[i] = '0' + (n % 16);
		else if (c == 'x' && check == 0)
			str[i] = 'a' + (n % 16) - 10;
		else if (c == 'X' && check == 0)
			str[i] = 'A' + (n % 16) - 10;
		else if (check == 1)
			str[i] = 'a' + (n % 16) - 10;
		n = n / 16;
		i--;
	}
	ft_putstr(list, str);
	free(str);
}
