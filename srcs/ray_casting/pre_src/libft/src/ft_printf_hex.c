/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:34:40 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:13:37 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_hexlen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	lowercase_hex(unsigned int nb)
{
	unsigned int	n;

	n = nb;
	while (nb >= 16)
	{
		lowercase_hex(nb / 16);
		nb %= 16;
	}
	printf_c("0123456789abcdef"[nb]);
	return (ft_hexlen(n));
}

int	uppercase_hex(unsigned int nb)
{
	unsigned int	n;

	n = nb;
	while (nb >= 16)
	{
		uppercase_hex(nb / 16);
		nb %= 16;
	}
	printf_c("0123456789ABCDEF"[nb]);
	return (ft_hexlen(n));
}
