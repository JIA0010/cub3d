/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:30:17 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/22 16:29:04 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	i;

	i = 0;
	while (i < maxlen && s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	strnlen_dest;
	unsigned int	strlen_src;

	strnlen_dest = ft_strnlen(dst, dstsize);
	strlen_src = ft_strlen(src);
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize == 0 && dst == NULL)
		return (strlen_src);
	if (dstsize <= strnlen_dest)
		return (dstsize + strlen_src);
	else
	{
		ft_strlcpy(dst + strnlen_dest, src, dstsize - strnlen_dest);
		return (strnlen_dest + strlen_src);
	}
}

// #include <libc.h>
// #include <assert.h>
// int main(void)
// {
// 	// char s[4] = "123";
// 	printf("original=%lu, ft=%lu\n",
// 				strlcat(s, "424242", 2), ft_strlcat(s, "424242", 2));
// }

// int	main(void)
// {
// 	char	dest[100] = "Hello ";
// 	char	src[] = "World";
// 	char	dest1[100] = "Hello ";
// 	char	src1[] = "World";

// 	// unsigned int	result = strlcat(dest, src, 20);
// 	// printf("%s %u\n", dest, result);
// 	unsigned int	result1 = ft_strlcat(dest1, src1, 20);
// 	printf("%s %u\n", dest1, result1);
// 	printf("%s %u\n", src1, result1);
// 	return (0);
// }

// int	main(void)
// {
// 	char *dst1 = calloc(100, sizeof(char));
// 	char *dst2 = calloc(100, sizeof(char));

// 	char *src1 = calloc(100, sizeof(char));
// 	char *src2 = calloc(100, sizeof(char));
// 	for (int i = 0; i < 99; i++)
// 	{
// 		src1[i] = i + 1;
// 		src2[i] = i + 1;
// 	}
// 	printf("%zu %zu\n", strnlen(dst1, 50), strnlen(src1, 50));
// 	printf("ft %zu\n", ft_strlcat(dst1, src1, 50));
// 	printf("   %zu\n", strlcat(dst2, src2, 50));
// 	return (0);
// }
