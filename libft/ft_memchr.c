/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwhitfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:30:02 by rwhitfor          #+#    #+#             */
/*   Updated: 2021/09/17 18:30:02 by rwhitfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;
	size_t			i;

	str = (unsigned char *) s;
	chr = (unsigned char) c;
	i = 0;
	while (str[i] != '\0' && i < n)
	{
		if (str[i] == chr)
			return ((unsigned char *)s + i);
		i++;
	}
	if (str[i] == '\0' && chr == '\0')
		return ((unsigned char *)s + i);
	return (NULL);
}
