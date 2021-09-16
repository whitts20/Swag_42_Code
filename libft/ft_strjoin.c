#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*con;
	char	*str;
	
	i = 0;
	j = 0;
	if (ft_strlen)
	con = (char *) malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) - 1));
	if (con == NULL)
	{
		
		return (con);
	}
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
