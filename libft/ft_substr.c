#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	sub = (char *) malloc (sizeof(char) * len);
	i = 0;
	if (sub == NULL)
		return (NULL);
	while (i <= len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
