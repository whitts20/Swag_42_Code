#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dst);
	j = 0;
	k = ft_strlen(src);
	while (src[j] != '\0' && (j < (dstsize - i - 1)))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (!(dstsize == 0 || ft_strlen(dst) > dstsize))
		dst[i + j] = '\0';
	return (i + k);
}
