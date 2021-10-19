/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwhitfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:55:30 by rwhitfor          #+#    #+#             */
/*   Updated: 2021/10/19 13:55:30 by rwhitfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	if (s == 0 || s[0] == 0)
		return (0);
	i = 1;
	count = 0;
	if (s[0] != c)
		count++;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static char	**ft_malloc(char const *s, char c)
{
	int		len;
	char	**str;

	if (s == NULL)
		return (NULL);
	len = ft_wordcount(s, c);
	str = malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	return (str);
}

static int	ft_nextword(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0' && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static char	**ft_free(char **str, int i)
{
	int	j;

	j = 0;
	while (j < i && str[j] != 0)
	{
		free(str[j]);
		j++;
	}
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		a;
	int		i;
	int		j;
	char	**str;

	a = 0;
	i = -1;
	str = ft_malloc(s, c);
	if (!str)
		return (NULL);
	while (++i < ft_wordcount(s, c))
	{
		j = 0;
		str[i] = malloc(ft_nextword(s, c, a) + 1);
		if (!(str[i]))
			return (ft_free(str, i));
		while (s[a] != '\0' && s[a] == c)
			a++;
		while (s[a] != '\0' && s[a] != c)
			str[i][j++] = s[a++];
		str[i][j] = '\0';
	}
	str[i] = NULL;
	return (str);
}
