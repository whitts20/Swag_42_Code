#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_read
{
	va_list	args;
	int		count;
}			t_read;

int	ft_printf(const char *str, ...);
void	ft_check(t_read	*list, char *str, int len);
static t_read	*ft_arg_dec(void);
void	ft_putchar(t_read	*list, char c);
void	ft_putstr(t_read	*list, char *s);
void	ft_putnbr(t_read	*list, int n);
void	ft_putunbr(t_read	*list, unsigned int n);
void	ft_puthex(t_read	*list, unsigned long n, char c, int check);

#endif