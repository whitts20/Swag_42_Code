/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwhitfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:30:02 by rwhitfor          #+#    #+#             */
/*   Updated: 2021/09/17 18:30:02 by rwhitfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*con;

	i = 0;
	j = 0;
	con = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) - 1));
	if (con == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		con[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		con[i + j] = s2[j];
		j++;
	}
	con[i + j] = '\0';
	return (con);
}
