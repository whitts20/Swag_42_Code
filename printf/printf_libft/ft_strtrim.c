/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwhitfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:55:31 by rwhitfor          #+#    #+#             */
/*   Updated: 2021/10/19 13:55:31 by rwhitfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*trim;

	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	if (set == NULL)
		return (ft_strdup(s1));
	while ((s1[start] != '\0') && (ft_strchr(set, s1[start]) != NULL))
		start++;
	while (end > start && ft_strchr(set, s1[end]) != NULL)
		end--;
	trim = (char *)malloc(sizeof(char) * (end - start + 2));
	if (trim == NULL)
		return (NULL);
	while (i <= end - start)
	{
		trim[i] = s1[start + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
