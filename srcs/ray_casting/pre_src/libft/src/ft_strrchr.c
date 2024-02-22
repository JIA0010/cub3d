/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:32:32 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:12:24 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	str_len;

	str_len = ft_strlen(str);
	c = c % 256;
	if (str[str_len] == (char)c)
		return ((char *)(str + str_len));
	while (str_len > 0)
	{
		if (str[str_len - 1] == (char)c)
			return ((char *)(str + str_len - 1));
		str_len--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char str[] = "aaaabaaa";
// 	ft_strrchr(str, 'b');
// 	printf("%ld", ft_strrchr(str, 'b') - str);
// }