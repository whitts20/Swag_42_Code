#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	s;
	size_t	e;
	char	*trim;

	i = 0;
	s = 0;
	e = 0;
	while (s1[i] == set[i])
	{
		s++;
		i++;
	}
	i = ft_strlen(s1) - 1;
	j = ft_strlen(set) - 1;
	while (s1[i] == set[j])
	{
		e++;
		i--;
		j--;
	}
	trim = (char *) malloc(sizeof(char) * (ft_strlen(s1) - s - e));
	if (trim == NULL)
		return (NULL);
	i = s;
	j = 0;
	while (i < ft_strlen(s1) - 1 - e)
	{
		trim[j] = s1[i];
		i++;
		j++;
	}
	trim[j] = '\0';
	return (trim);
}
