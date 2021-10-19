#include "libft.h"

char	*ft_hexstr(unsigned long n, int *i)
{
	char	*str;

	while (n > 15)
	{
		n = n / 16;
		*i += 1;
	}
	str = (char *)malloc(sizeof(char) * (*i + 1));
	if (str == NULL)
		return (NULL);
	str[*i] = '\0';
	return (str);
}
