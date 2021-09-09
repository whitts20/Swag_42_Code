#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *) malloc(sizeof(char) * count * size);
	while (i <= (count * size))
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
