/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:32:14 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/30 14:59:44 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dstc;
	const unsigned char	*srcc;

	dstc = (unsigned char *)dst;
	srcc = (const unsigned char *)src;
	if (dstc == NULL && srcc == NULL)
		return (NULL);
	if (srcc > dstc)
		ft_memcpy(dstc, srcc, len);
	else
	{
		while (len > 0)
		{
			dstc[len - 1] = srcc[len - 1];
			len--;
		}
	}
	return (dst);
}

// int	main(void)
// {
// 	char *src = "the cake is a lie !\0I'm hidden lol\r\n";
// 	char buff[0xF0];

// 	char *r1 = memmove(buff, src, 100);
// 	char *r2 = ft_memmove(buff, src, 100);
// 	printf("   %s\nft %s", r1, r2);
// 	return (0);
// }

// int	main(void)
// {
// 	char str1[] = "abcdefghijklmnopqrstuvwxyz";
// 	char str2[] = "abcdefghijklmnopqrstuvwxyz";

// 	printf("   移動前：%s\n",str1);
// 	printf("ft 移動前：%s\n",str2);
// 	memmove(str1+5, str1, 10);        /* 重複エリアのコピー */
// 	ft_memmove(str2+5, str2, 10);
// 	printf("   移動後：%s\n",str1);
// 	printf("ft 移動後：%s\n",str2);
// 	return (0);
// }
