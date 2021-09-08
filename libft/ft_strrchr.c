#include "libft.h"

char	*strrchr(const char *s, int c)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			pos = i;
		i++;
	}
	if (pos != 0)
		return (s + pos);
	if (s[i] == '\0' && c == '\0')
		return (s + i);
	return (NULL);
}
