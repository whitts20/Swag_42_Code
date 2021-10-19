/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwhitfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:55:28 by rwhitfor          #+#    #+#             */
/*   Updated: 2021/10/19 13:55:28 by rwhitfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_hexstr(unsigned long n, int *i)
{
	char	*str;

	while (n > 15)
	{
		n = n / 16;
		*i += 1;
	}
	str = (char *)malloc(sizeof(char) * (*i + 1));
	if (str == NULL)
		return (NULL);
	str[*i] = '\0';
	return (str);
}
