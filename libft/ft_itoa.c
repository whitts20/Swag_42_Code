#include "libft.h"

int	ft_count(int n)
{
	int	count;
	int	num;

	count = 0;
	if (n < 0)
	{
		num = -n;
		count++;
	}
	else
		num = n;
	if (n == 0)
		count = 1;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_count(n);
	str = (char *) malloc(sizeof(char) * i);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		str[i - 1] = ((n % 10) + '0');
		n = n / 10;
		i--;
	}
	return (str);
}
