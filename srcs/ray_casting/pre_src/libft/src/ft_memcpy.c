/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:57:51 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:14:00 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memcpy(void *dest, const void *src, int n)
{
	char		*c_dest;
	const char	*c_src;
	int			i;

	c_dest = (char *)dest;
	c_src = (const char *)src;
	i = 0;
	if (c_dest == NULL && c_src == NULL)
		return (NULL);
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*str2;
// 	char	*str3;
// 	char	*str4;

// 	str = NULL;
// 	str2 = NULL;
// 	str3 = NULL;
// 	str4 = NULL;

// 	printf("移動前：%s\n", str);
// 	memcpy(str, str2, 1); /* 重複エリアのコピー */
// 	printf("移動後：%s\n", str);
// 	printf("移動前：%s\n", str3);
// 	ft_memcpy(str3, str4, 1); /* 重複エリアのコピー */
// 	printf("移動後：%s\n", str3);
// 	return (0);
// }

// int	main(void)
// {
// 	void *src = NULL;
// 	void *dest = NULL;
// 	int size = 10;

// 	ft_memcpy(dest, src, size);

// 	printf("After calling ft_memcpy\n");

// 	return (0);
// }