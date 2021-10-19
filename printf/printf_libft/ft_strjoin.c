/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwhitfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:55:30 by rwhitfor          #+#    #+#             */
/*   Updated: 2021/10/19 13:55:30 by rwhitfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*con;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	con = (char *)malloc(sizeof(con) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (con == NULL)
		return (NULL);
	ft_strlcpy(con, s1, ft_strlen(s1) + 1);
	ft_strlcat(con, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (con);
}
