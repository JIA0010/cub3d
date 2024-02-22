/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:07:39 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:14:29 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	parse_digits(const char *str, int sign)
{
	long	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		if ((res > LONG_MAX / 10) || (res == LONG_MAX / 10 && (*str
					- '0') > LONG_MAX % 10))
		{
			if (sign == 1)
				return ((int)(LONG_MAX));
			else
				return ((int)(LONG_MIN));
		}
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	return (parse_digits(str, sign));
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;

// 	str1 = "9223372036854775807";
// 	str2 = "-9223372036854775808";

// 	printf("%d\n", ft_atoi(str2));
// 	printf("%d\n", atoi(str2));

// 	return (0);
// }
