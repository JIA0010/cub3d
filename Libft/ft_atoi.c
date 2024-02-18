/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:57:05 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/18 16:07:49 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stddef.h>
#include "libft.h"

static int	is_overflow(const char c, long num, int minus)
{
	if (minus == 1 && num > LONG_MAX / 10)
		return (-1);
	else if (minus == 1 && (num == LONG_MAX / 10 && c - '0' >= LONG_MAX % 10))
		return (-1);
	else if (minus * num < LONG_MIN / 10)
		return (0);
	else if (minus * num == LONG_MIN / 10 && c - '0' >= -(LONG_MIN % 10))
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	long	num;
	int		minus;

	num = 0;
	minus = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		if (is_overflow(*str, num, minus) == 0)
			return ((int)LONG_MIN);
		else if (is_overflow(*str, num, minus) == -1)
			return ((int)LONG_MAX);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * minus);
}

// int	main(void)
// {
// 	// //long long の最小値-9223372036854775808
// 	// char	*str1 = "9223372036854775808";
// 	// char	*str2 = "-9223372036854775809";
// 	// //unsigned long long の最大値18446744073709551615
// 	// char	*str3 = "18446744073709551615";
// 	char	*str4 = "2147483648";
// 	// char	*str5 = "18446744073709551614";

// 	// printf("%d\n", atoi(str1));
// 	// printf("%d\n", atoi(str2));
// 	// printf("%d\n", atoi(str3));
// 	printf("%d\n", atoi(str4));
// 	// printf("%d\n", atoi(str5));
// 	// printf("ft %d\n", ft_atoi(str1));
// 	// printf("ft %d\n", ft_atoi(str2));
// 	// printf("ft %d\n", ft_atoi(str3));
// 	printf("ft %d\n", ft_atoi(str4));
// 	// printf("ft %d\n", ft_atoi(str5));
// 	printf("%d %ld", INT_MAX, LONG_MAX);
// 	return (0);
// }
