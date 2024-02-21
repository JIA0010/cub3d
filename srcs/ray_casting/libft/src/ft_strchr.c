/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:05:04 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:13:00 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

// int	main(void)
// {
// 	char	*s;

// 	s = "libft-test-tokyo";
// 	printf("%s\n", ft_strchr(s, 'l' - 256));
// 	printf("%s\n", strchr(s, 'l' - 256));
// 	// ft_strchr(s, 'i' - 256);
// 	// strchr(s, 'i' - 256);
// 	return (0);
// }