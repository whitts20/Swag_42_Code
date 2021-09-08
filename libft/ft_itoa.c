#include "libft.h"

char	*ft_itoa(int n)
{
	int		count;
	int		num;
	char	*str;

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
	while (n != 0)
	{
		num = num / 10;
		count++;
	}
	str = (char *) malloc(sizeof(char) * count);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		str[count - 1] = ((n % 10) + '0');
		n = n / 10;
		count--;
	}
	return (str);
}
