#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;
	size_t			i;

	str = (unsigned char *) s;
	chr = (unsigned char) c;
	i = 0;
	while (str[i] != '\0' && i < n)
	{
		if (str[i] == chr)
			return ((unsigned char *)s + i);
		i++;
	}
	if (str[i] == '\0' && chr == '\0')
		return ((unsigned char *)s + i);
	return (NULL);
}
