/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwhitfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:10:55 by rwhitfor          #+#    #+#             */
/*   Updated: 2021/10/25 15:10:55 by rwhitfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ptrstr(unsigned long n, int *i)
{
	char	*str;
	int		j;

	j = *i;
	while (n >= 16)
	{
		n = n / 16;
		j += 1;
	}
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (str == NULL)
		return (NULL);
	str[j] = '\0';
	*i = j;
	return (str);
}

void	ft_putptr(t_read	*list, unsigned long n)
{
	char	*str;
	int		i;

	i = 1;
	str = ft_ptrstr(n, &i);
	i -= 1;
	ft_putstr(list, "0x");
	while (i >= 0)
	{
		if ((n % 16) < 10)
			str[i] = '0' + (n % 16);
		else
			str[i] = 'a' + (n % 16) - 10;
		n = n / 16;
		i -= 1;
	}
	ft_putstr(list, str);
	free(str);
}
