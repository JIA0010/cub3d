/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:19:21 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/26 16:23:29 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(src);
	if (dstsize == 0)
		return (n);
	else
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (n);
}

// int	main(void)
// {
// 	char *str = "BBBB";
// 	char buff1[0xF00];
// 	char buff2[0xF00];

// 	__builtin___memset_chk (buff1, 'A', 20, __builtin_object_size (buff1, 0));
// 	__builtin___memset_chk (buff2, 'A', 20, __builtin_object_size (buff2, 0));
// 	__builtin___strlcpy_chk (buff1, str, sizeof(buff1), __builtin_object_size
// (buff1, 2 > 1 ? 1 : 0));
// 	ft_strlcpy(buff2, str, sizeof(buff2));
// 	printf("   %s\nft %s\n", buff1, buff2);
// }
// int	main(void)
// {
// 	char	a[10] = "ABCDEFGH";
// 	char	b[10] = "12345";
// 	char	c[10] = "ABCDEFGH";
// 	char	d[10] = "12345";

// 	strlcpy(b, a, 3);
// 	printf("strlcpyの実行結果(3文字)\n%s\n", b);
// 	strlcpy(b, a, 8);
// 	printf("strlcpyの実行結果(8文字)\n%s\n", b);
// 	ft_strlcpy(d, c, 3);
// 	printf("実行結果(3文字)\n%s\n", d);
// 	ft_strlcpy(d, c, 8);
// 	printf("実行結果(8文字)\n%s\n", d);
// }
