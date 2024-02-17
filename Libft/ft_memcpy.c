/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:17:49 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/30 14:58:58 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dstc;
	const unsigned char	*srcc;
	size_t				i;

	dstc = (unsigned char *)dst;
	srcc = (const unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dstc[i] = srcc[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char src[] = "test basic du memcpy !";
// 	// char buff1[22];
// 	char *r1 = memcpy(((void *)0), src, 3);
// 	char *r2 = ft_memcpy(((void *)0), src, 3);
// 	printf("original=%s\nft=%s\n", r1, r2);
// 	return (0);
// }

// int	main(void)
// {
// 		char str1[128] = {1,1,1,1,1,1,1};
// 		char str2[] = "ab\0cde";/* 途中に空文字のある文字列 */
// 		char str3[128] = {1,1,1,1,1,1,1};
// 		char str4[] = "ab\0cde";/* 途中に空文字のある文字列 */
// 		int i;

// 		printf("   コピー前　中身の確認\n");
// 		for (i=0; i<7; i++)
// 			printf("%#x ",str1[i]);
// 		printf("\n");
// 		printf("ft コピー前　中身の確認\n");
// 		for (i=0; i<7; i++)
// 			printf("%#x ",str3[i]);
// 		printf("\n");
// 		memcpy(str1, str2, 5);
// 		ft_memcpy(str3, str4, 5);
// 		printf("   コピー後　中身の確認\n");
// 		for (i=0; i<7; i++)
// 			printf("%#x ",str1[i]);
// 		printf("\n");
// 		printf("ft コピー後　中身の確認\n");
// 		for (i=0; i<7; i++)
// 			printf("%#x ",str3[i]);
// 		printf("\n");
// 		return 0;
// }
