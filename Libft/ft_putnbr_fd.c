/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:46:51 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/30 15:08:20 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include "libft.h"

void	ft_putnbr_fd_ll(long long n, int fd)
{
	if (n < 10)
	{
		n += '0';
		write(fd, &n, 1);
	}
	else
	{
		ft_putnbr_fd_ll(n / 10, fd);
		ft_putnbr_fd_ll(n % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	nb;

	nb = (long long)n;
	if (nb < 0)
	{
		nb *= -1;
		write(fd, "-", 1);
	}
	ft_putnbr_fd_ll(nb, fd);
}

// int	main(void)
// {
// 	long long	n = -2147483648;

// 	ft_putnbr_fd(n, 1);
// 	return (0);
// }
