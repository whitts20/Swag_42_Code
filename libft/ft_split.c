#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_free(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		free(s);
		i++;
	}
	free(s);
}

char	*ft_check(char const *s, char c)
{
	int		a;
	int		count;
	int		check;
	char	*str;

	a = 0;
	count = 0;
	check = 0;
	while (s[a] == c)
	{
		count++;
		a++;
	}
	while (s[a] != '\0')
		a++;
	if (s[a - 1] != c)
		check = 1;
	str = (char *) malloc(sizeof(char) * (a - count + check));
	if (str == NULL)
		return (NULL);
	a = 0;
	while (s[a + count] != '\0')
	{
		str[a] = s[a + count];
		a++;
	}
	str[a] = '\0';
	if ((str[a - 1] != c) && (check == 1))
	{
		str[a] = c;
		str[a + 1] = '\0';
	}
	return (str);
}

int	ft_wordlen(char const *s, char c)
{
	int			len;
	static int	pos;

	if (!pos)
		pos = 0;
	len = 1;
	while (s[pos] != '\0')
	{
		while (s[pos] == c)
		{
			if ((s[pos] == c) && (s[pos - 1] != c))
			{
				pos++;
				return (len);
			}
			pos++;
		}
		while (s[pos] != c)
		{
			len++;
			pos++;
		}
	}
	return (0);
}

char	**ft_mem(char const *s, char c)
{
	int		m;
	int		n;
	int		o;
	int		len;
	char	**split;

	m = 0;
	len = 1;
	while (s[m] != '\0')
	{
		if ((s[m] == c) && s[m - 1] != c)
			len++;
		m++;
	}
	split = (char **) malloc(sizeof(char *) * len);
	if (split == NULL)
		return (NULL);
	n = 0;
	while (n < len - 1)
	{
		split[n] = (char *) malloc(sizeof(char) * (ft_wordlen(s, c)));
		if (split[n] == NULL)
		{
			o = n;
			n = 0;
			while (n < o)
			{
				ft_free(split[n]);
				n++;
			}
			return (split);
		}
		n++;
	}
	if (n == len - 1)
	{
		split[n] = NULL;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	*s2;
	char	**str;

	i = 0;
	j = 0;
	k = 0;
	s2 = ft_check(s, c);
	str = ft_mem(s2, c);
	while (s2[i] != '\0')
	{
		if (s2[i] == c)
		{
			str[j][k] = '\0';
			j++;
			i++;
			k = 0;
			if (s2[i + 1] == '\0')
				break ;
			while (s2[i] == c)
				i++;
		}
		else
		{
			str[j][k] = s2[i];
			i++;
			k++;
		}
	}
	return (str);
}
