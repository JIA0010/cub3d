/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:35:47 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:13:23 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	printf_u(unsigned int nb)
{
	unsigned int	n;
	int				len;

	len = 0;
	n = nb;
	if (n >= 10)
	{
		printf_u(n / 10);
		printf_u(n % 10);
	}
	else
		printf_c(n + '0');
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
