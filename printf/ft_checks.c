#include "ft_printf.h"

void	ft_putchar(t_read	*list, char c)
{
	write(1, &c, 1);
}

void	ft_putstr(t_read	*list, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(t_read	*list, int n)
{
	unsigned int	var;

	if (n < 0)
	{
		ft_putchar(list, '-');
		var = -n;
	}
	else
	{
		var = n;
	}
	if (var >= 10)
	{
		ft_putnbr(list, (var / 10));
	}
	ft_putchar(list, (var % 10 + 48));
}

void	ft_putunbr(t_read	*list, unsigned int n)
{
	if (n >= 10)
	{
		ft_putunbr(list, (n / 10));
	}
	ft_putchar(list, (n % 10 + 48));
}

void	ft_puthex(t_read	*list, unsigned long n, char c, int check)
{
	char	*str;
	int		i;

	i = 1;
	str = ft_hexstr(n, &i);
	if (check = 1) 
		ft_putstr(list, "0x");
	i--;
	while (i >= 0)
	{
	if (n % 16 < 10)
		str[i] = '0' + (n % 16);
	else if (c == 'x')
		str[i] = 'a' + (n % 16) - 10;
	else
		str[i] = 'A' + (n % 16) - 10;
	}
}