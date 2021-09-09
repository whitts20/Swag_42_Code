#include "libft.h"

int	ft_start(char const *s1, char const *set)
{
	int		i;
	int		s;

	i = 0;
	s = 0;
	while (s1[i] == set[i])
	{
		s++;
		i++;
	}
	return (s);
}

int	ft_end(char const *s1, char const *set)
{
	int	k;
	int	l;
	int	e;

	k = ft_strlen(s1) - 1;
	l = ft_strlen(set) - 1;
	e = 0;
	while (s1[k] == set[l])
	{
		e++;
		k--;
		l--;
	}
	return (e);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		m;
	int		n;
	char	*trim;

	trim = (char *) malloc(sizeof(char)
			* (ft_strlen(s1) - ft_start(s1, set) - ft_end(s1, set)));
	if (trim == NULL)
		return (NULL);
	m = ft_start(s1, set);
	n = 0;
	while (m < (int)ft_strlen(s1) - 1 - ft_end(s1, set))
	{
		trim[n] = s1[m];
		m++;
		n++;
	}
	trim[n] = '\0';
	return (trim);
}
