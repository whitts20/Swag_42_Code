SRCS =	srcs/ft_checks.c \
		srcs/ft_printf.c

OBJS = $(SRCS:.c=.o)

INCS = hdrs
NAME = libftprintf.a
LIBFT = libft.a
LIBC = ar -rcs
COMP = gcc
RMVE = rm -f
EFLAGS = -Wall -Wextra -Werror

.c.o:
		$(COMP) $(EFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

$(NAME): $(OBJS)
		$(MAKE) bonus -C ./printf_libft
		cp printf_libft/libft.a $(NAME)
		$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

clean:
		$(MAKE) clean -C ./printf_libft
		$(RMVE) $(OBJS)

fclean: 
		$(MAKE) fclean -C ./printf_libft
		$(RMVE) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re