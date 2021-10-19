/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwhitfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:55:28 by rwhitfor          #+#    #+#             */
/*   Updated: 2021/10/19 13:55:28 by rwhitfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *) malloc(sizeof(char) * count * size);
	if (str == NULL)
		return (NULL);
	while (i <= (count * size))
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
