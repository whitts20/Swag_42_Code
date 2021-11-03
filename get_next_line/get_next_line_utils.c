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

char	*ft_strdup(char *str1)
{
	int	i;
	char	*str2;

	i = 0;
	str2 = (char *) malloc(sizeof(char) * ft_strlen(str1) + 1);
	if (str2 == NULL)
		return (NULL);
	while (str1[i] != '\0')
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

char	*ft_null(void)
{
	char	*line;

	line = (char *)malloc(sizeof(char) * 1);
	line[0] = '\0';
	return(line);
}

char	*ft_strtrim(char *str, char c)
{
	int		i;
	int		check;
	char	*trim;

	i = 0;
	check = 0;
	if (c == '\n')
		check = 1;
	while (str[i] != c)
		i++;
	trim = (char *)malloc(sizeof(char) * (i + check));
	i = 0;
	while (str[i] != c)
	{
		trim[i] = str[i];
		i++;
	}
	if (check == 1)
	{
		trim[i] = '\n';
		i++;
	}
	trim[i] = '\0';
	//free(str);
	return (trim);
}

char	*ft_excess(char	*str, char c)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (str[i] != c)
		i++;
	temp = (char *) malloc(sizeof(char) * (ft_strlen(str) + 1 - i));
	if (temp == NULL)
		return (NULL);
	i++;
	while (str[i] != '\0')
	{
		temp[j] = str[i];
		i++;
		j++;
	}
	temp[j] = '\0';
	//free(str);
	return (temp);
}
