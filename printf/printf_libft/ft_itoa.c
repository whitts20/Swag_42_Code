/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwhitfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:55:29 by rwhitfor          #+#    #+#             */
/*   Updated: 2021/10/19 13:55:29 by rwhitfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(int n)
{
	int	count;
	int	num;

	count = 1;
	if (n < 0)
	{
		num = -n;
		count++;
	}
	else
		num = n;
	if (n == 0)
		count = 2;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int				i;
	char			*str;
	unsigned int	nbr;

	i = ft_count(n);
	str = (char *) ft_calloc(sizeof(char), i);
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		nbr = -n;
	}
	else
		nbr = n;
	str[--i] = '\0';
	while (nbr != 0)
	{
		str[i - 1] = ((nbr % 10) + '0');
		nbr = nbr / 10;
		i--;
	}
	return (str);
}
