/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:31:47 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:13:08 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n / 10 > 0)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	digit = '0' + (n % 10);
	write(fd, &digit, 1);
}

// int	main(void)
// {
// 	int number = -12345;
// 	int fd = 1; // 標準出力へのファイルディスクリプタ (1: stdout)

// 	ft_putnbr_fd(number, fd);

// 	return (0);
// }