#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;
	char	*str;

	i = 0;
	str = (char *) malloc(sizeof(char) * ft_strlen(s));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s);
		i++;
	}
	str[i] = '\0';
	return (str);
}
