/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:12:56 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/29 19:45:38 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1c;
	unsigned char	*s2c;
	size_t			i;

	i = 0;
	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	while (i < n)
	{
		if (s1c[i] != s2c[i])
			return (s1c[i] - s2c[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char *s1 = "\xff\xaa\xde\xffMACOSX\xff";
// 	char *s2 = "\xff\xaa\xde\x02";
// 	size_t size = 5;
// 	int i1 = memcmp(s1, s2, size);
// 	int i2 = ft_memcmp(s1, s2, size);
// 	printf("   %d\nft %d\n", i1, i2);
// 	char *s3 = "\xff\xaa\xde\200";
// 	char *s4 = "\xff\xaa\xde\0";
// 	size_t size1 = 8;
// 	int i3 = memcmp(s3, s4, size1);
// 	int i4 = ft_memcmp(s3, s4, size1);
// 	printf("   %d\nft %d\n", i3, i4);
// 	char *s5 = "\xff\0\0\xaa\0\xde\xffMACOSX\xff";
// 	char *s6 = "\xff\0\0\xaa\0\xde\x00MBS";
// 	size_t size2 = 9;
// 	int i5 = memcmp(s5, s6, size2);
// 	int i6 = ft_memcmp(s5, s6, size2);
// 	printf("   %d\nft %d\n", i5, i6);
// }
// int	main(void)
// {
// 	char buf1[] = "\0abc\0de";      /* 途中に空文字のある文字列 */
// 	char buf2[] = "\0abc\0de";
// 	char buf3[] = "\0abcdef";

// 	if (memcmp(buf1, buf2, 5) == 0)
// 		printf("   buf1 = buf2\n");
// 	else
// 		printf("   buf1 != buf2\n");

// 	if (memcmp(buf1, buf3, 5) == 0)
// 		printf("   buf1 = buf3\n");
// 	else
// 		printf("   buf1 != buf3\n");

// 	if (ft_memcmp(buf1, buf2, 5) == 0)
// 		printf("ft buf1 = buf2\n");
// 	else
// 		printf("ft buf1 != buf2\n");

// 	if (ft_memcmp(buf1, buf3, 5) == 0)
// 		printf("ft buf1 = buf3\n");
// 	else
// 		printf("ft buf1 != buf3\n");
// 	return (0);
// }
