/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:45:11 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:12:48 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	i = 0;
	src_len = ft_strlen(src);
	if (size != 0)
	{
		while (i < size - 1 && i < src_len)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

// int	main(void)
// {
// 	char	*dst1;
// 	char	*dst2;
// 	char	*src1;

// 	dst1 = calloc(10, sizeof(char));
// 	dst2 = calloc(10, sizeof(char));
// 	src1 = calloc(10, sizeof(char));
// 	memset(src1, 'z', 9);
// 	memset(dst1, 'z', 9);
// 	// memset(dst2, 'z', 9);
// 	*dst2 = "world";
// 	// ft_strlcpy(dst1, src1, 10);
// 	ft_strlcpy(dst2, dst2, 10);
// 	strlcpy(dst1, dst2, 10);
// 	for (int i = 0; i < 10; i++)
// 		printf("%c", dst1[i]);
// 	printf("\n");
// 	for (int i = 0; i < 10; i++)
// 		printf("%c", dst2[i]);
// 	printf("\n");
// }
