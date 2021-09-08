#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		a;
	int		b;
	char	*con;

	i = 0;
	j = 0;
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	con = (char *) malloc (sizeof(char) * (a + b - 1));
	if (con == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		con[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		con[i + j] = s2[j];
		j++;
	}
	con[i + j] = '\0';
	return (con);
}
