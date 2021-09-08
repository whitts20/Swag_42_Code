#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	len1;
	int	len2;
	char *trim;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(set);
	trim = (char *) malloc(sizeof(char) * (len1 - (2 * (len2 - 1))));
	while (i < )
	// Trim len2 of start and end of s1 and put it in trim.
}