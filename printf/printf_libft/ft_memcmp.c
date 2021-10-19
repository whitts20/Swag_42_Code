/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwhitfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:55:29 by rwhitfor          #+#    #+#             */
/*   Updated: 2021/10/19 13:55:29 by rwhitfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *) s1;
	b = (unsigned char *) s2;
	i = 0;
	if (s1 == s2)
		return (0);
	while (i < n)
	{
		if (*a != *b)
		{
			break ;
		}
		a++;
		b++;
		i++;
	}
	if (i == n)
	{
		a--;
		b--;
	}
	return (*a - *b);
}
