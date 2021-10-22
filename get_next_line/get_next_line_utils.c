/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwhitfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:05:26 by rwhitfor          #+#    #+#             */
/*   Updated: 2021/10/20 17:05:26 by rwhitfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strlcat(char *dst, char *src, int dstsize)
{
	int	i;
	int	j;
	int	k;

	i = ft_strlen(dst);
	j = 0;
	k = ft_strlen(src);
	if (dstsize < i + 1)
		return (dstsize + k);
	else if (dstsize > i + 1)
	{
		while (src[j] != '\0' && (j < (dstsize - i - 1)))
		{
			dst[i + j] = src[j];
			j++;
		}
	}
	dst[i + j] = '\0';
	return (i + k);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (src[counter] != '\0')
	{
		counter++;
	}
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (counter);
}

int	ft_numofnl(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

/*int ft_toolong(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (count >= 2 && str[i] != '\0')
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}*/