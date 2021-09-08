#include "libft.h"

void	*memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;
	int				i;

	str = (unsigned char *) s;
	chr = (unsigned char) c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			return (str[i]);
		i++;
	}
	if (str[i] == '\0' && chr == '\0')
		return (str[i]);
	return (NULL);
}
