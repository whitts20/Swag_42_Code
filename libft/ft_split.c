#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	**ft_mem(char const *s, char c)
{
	int		m;
	int		n;
	int		len;
	int		len2;
	char	**split;

	m = 0;
	n = 0;
	len = 0;
	len2 = 0;
	while (s[m] != '\0')
	{
		if (s[m] == c || s[m] == '\0')
			len++;
		m++;
	}
	split = (char **) malloc(sizeof(char *) * len);
	m = 0;
	len2 = 1;
	while ((s[m] != '\0') && (n < len))
	{
		if (s[m] == c || s[m] == '\0')
		{
			split[n] = (char *) malloc(sizeof(char) * len2);
			n++;
			len2 = 1;
		}
		m++;
		len2++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	i = 0;
	j = 0;
	k = 0;
	str = ft_mem(s, c);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			str[j][k] = '\0';
			j++;
			i++;
			k = 0;
			printf("%s", "\n");
		}
		else
		{
			str[j][k] = s[i];
			printf("%c", str[j][k]);
			i++;
			k++;
		}
	}
	str[j][k] = '\0';
	return (str);
}

int	main(void)
{
	ft_split("lorem1ipsum1dolor1sit1amet", '1');
}
