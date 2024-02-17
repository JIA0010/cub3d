/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:52:42 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/30 15:45:42 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static size_t	ft_recursive_power(long long nb, size_t power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

static size_t	ft_count_beams(size_t count, long long nb)
{
	while (nb > 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

static char	*ft_itoaputchar(char *str, long long nb, size_t i, size_t count)
{
	if (i == 1)
		str[0] = '-';
	if (nb == 0)
		str[0] = '0';
	while (i < count)
	{
		str[i] = nb / ft_recursive_power(10, count - i - 1) + '0';
		nb %= ft_recursive_power(10, count - i - 1);
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		count;
	size_t		i;
	long long	nb;

	i = 0;
	nb = (long long)n;
	if (nb <= 0)
	{
		nb *= -1;
		i++;
	}
	count = (ft_count_beams(i, nb));
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	return (ft_itoaputchar(str, nb, i, count));
}

// int	main(void)
// {
// 	int	n;
// 	n = 0;
// 	printf("%s\n", ft_itoa(n));
// 	return (0);
// }
