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

int	ft_printf(const char *str, ...)

#endif