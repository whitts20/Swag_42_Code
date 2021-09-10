#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	pos;

	i = 0;
	pos = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			pos = i;
		i++;
	}
	if (pos != -1)
		return ((char *)s + pos);
	if (s[i] == '\0' && c == '\0')
		return ((char *)s + i);
	return (NULL);
}
