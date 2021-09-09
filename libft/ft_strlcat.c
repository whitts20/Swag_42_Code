#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dst);
	j = 0;
	k = ft_strlen(src);
	if (dstsize < i + 1)
		return (dstsize + k);
	else if (dstsize > i + 1)
	{
		while (src[j] != '\0' && (j < (dstsize - i - 1)))
		{
			dst[i + j] = src[j];
			j++;
		}
	}
	dst[i + j] = '\0';
	return (i + k);
}
