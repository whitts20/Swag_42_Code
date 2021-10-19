/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwhitfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:55:29 by rwhitfor          #+#    #+#             */
/*   Updated: 2021/10/19 13:55:29 by rwhitfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	a = (unsigned char *) dst;
	b = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dst);
}
