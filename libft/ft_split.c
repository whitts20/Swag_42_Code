#include "libft.h"

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = 0;
	j = 0;
	k = 0;
	split = (char **) malloc(sizeof(char) * (ft_strlen(s)));
	i = 0;
	while (s[i] != '\0')
	{
		split[j][k] = s[i];
		if (s[i] == c)
		{
			j++;
			k = 0;
		}
		i++;
		k++;
	}
	split[j][k] = '\0';
	return (split);
}
