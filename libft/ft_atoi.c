#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	coefficient;
	int	output;

	i = 0;
	output = 0;
	while (str[i] == 32 || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		coefficient = -1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		output = output * 10 + (str[i] - '0');
		i++;
	}
	if (coefficient == -1)
		output = -output;
	return (output);
}
