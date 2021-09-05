#include "libft.h"

char	*ft_strdup(const char *str1)
{
	size_t	i;
	char	*str2;

	i = 0;
	str2 = (char *) malloc(sizeof(char) * ft_strlen(str1));
	if (str2 == NULL)
		return (NULL);
	while (str1[i] != '\0')
	{
		str2[i] = str1[i];
		i++;
	}
	return (str2);
}
