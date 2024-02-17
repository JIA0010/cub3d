/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:52:23 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/30 15:00:46 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	cc;

	i = 0;
	str = (unsigned char *)b;
	cc = (unsigned char)c;
	while (i < len)
	{
		str[i] = cc;
		i++;
	}
	return (b);
}

// int	main(void)
// {
// 	char str1[] = "0123456789";
// 	char str2[] = "0123456789";

// 	memset(str1+2, '*', 5);
// 	ft_memset(str2+2, '*', 5);
// 	printf("   %s\n",str1);
// 	printf("ft %s\n",str2);
// 	return (0);
// }
