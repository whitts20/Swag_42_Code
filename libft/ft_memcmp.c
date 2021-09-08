#include "libft.h"

int	memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *) s1;
	b = (unsigned char *) s2;
	i = 0;
	if (s1 == s2)
		return (0);
	while (i < n)
	{
		if (*a != *b)
		{
			break ;
		}
		a++;
		b++;
		i++;
	}
	return (*a - *b);
}
