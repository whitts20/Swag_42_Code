/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwhitfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:30:02 by rwhitfor          #+#    #+#             */
/*   Updated: 2021/09/17 18:30:02 by rwhitfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	var;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		var = -n;
	}
	else
	{
		var = n;
	}
	if (var >= 10)
	{
		ft_putnbr_fd((var / 10), fd);
	}
	ft_putchar_fd((var % 10 + 48), fd);
}
