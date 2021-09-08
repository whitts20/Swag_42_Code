#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t	n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if ((s1 - s2) > 0)
			return (1);
		else if ((s1 - s2) < 0)
			return (-1);
		i++;
	}
	if (i == n && n > 0)
		i--;
	if (s1[i] != '\0' && s2[i] == '\0')
		return (1);
	else if (s1[i] == '\0' && s2[i] != '\0')
		return (-1);
	return (0);
}
