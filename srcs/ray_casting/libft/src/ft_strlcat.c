/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:32:13 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:12:52 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	dest_len = 0;
	while (dest[dest_len] != '\0' && dest_len < size)
	{
		dest_len++;
	}
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	i = 0;
	while (src[i] != '\0' && (dest_len + i) < (size - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

// int	main(void)
// {
// 	char *str2 = "aaaaaaaa";
// 	char *str1 = NULL;

// 	printf("%ld\n", ft_strlcat(str1, str2, 0));
// 	printf("%ld\n", strlcat(str1, str2, 0));
// }