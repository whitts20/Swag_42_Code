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
#include <stdio.h>

char	*ft_hexstr(unsigned int n, int *i)
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
