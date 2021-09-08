#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *) dst;
	b = (unsigned char *) src;
	i = 0;
	if (a < b)
	{
		i = len;
		while (i > 0)
		{
			a[i] = b[i];
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			a[i] = b[i];
			i++;
		}
	}
}
