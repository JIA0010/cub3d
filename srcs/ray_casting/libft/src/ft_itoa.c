/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:15:18 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:14:10 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_convert_to_str(char *str, long num, int len, int sign)
{
	str[len] = '\0';
	while (len--)
	{
		str[len] = num % 10 + '0';
		num /= 10;
	}
	if (sign)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	long	temp;
	int		len;
	int		sign;

	sign = 0;
	if (n < 0)
	{
		temp = -(long)n;
		sign = 1;
	}
	else
		temp = n;
	len = ft_numlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_convert_to_str(str, temp, len, sign);
	return (str);
}

// int	main(void)
// {
// 	int a = 256;
// 	char *c = ft_itoa(a);
// 	printf("%s\n", c);
// }