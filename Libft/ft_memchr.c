/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:59:27 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/30 14:57:45 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		ch;
	const unsigned char	*str;
	size_t				i;

	ch = (unsigned char)c;
	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*str == ch)
			return ((void *)str);
		str++;
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char str[] = "abcdef\0ghij";    /* 途中に空文字のある文字列 */
// 	char	*p;
// 	p = memchr(str, 'h', 12);
// 	printf("検索文字は文字列の%ld番目\n",p - str);
// 	p = ft_memchr(str, 'h', 12);
// 	printf("検索文字は文字列の%ld番目\n",p - str);
// 	return (0);
// }
