/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:52:27 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:12:31 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*c_s1;
	unsigned char	*c_s2;

	c_s1 = (unsigned char *)s1;
	c_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (c_s1[i] != c_s2[i] || c_s1[i] == '\0' || c_s2[i] == '\0')
		{
			return (c_s1[i] - c_s2[i]);
		}
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char *str0 = "ABC";
// 	char *str1 = "ABD";
// 	char *str2 = "AAA";
// 	char *str3 = "ABCD";
// 	char *str4 = "AB";
// 	char *str5 = "B";
// 	char *str6 = "A";

// 	printf("strncmp    : ABC ABD   = %d\n", strncmp(str0, str1, 2));
// 	printf("ft_strncmp : ABC ABD   = %d\n\n", ft_strncmp(str0, str1, 2));

// 	printf("strncmp    : ABC ABC   = %d\n", strncmp(str0, str0, 2));
// 	printf("ft_strncmp : ABC ABC   = %d\n\n", ft_strncmp(str0, str0, 2));

// 	printf("strncmp    : ABC: AAA   = %d\n", strncmp(str0, str2, 2));
// 	printf("ft_strncmp : ABC: AAA   = %d\n\n", ft_strncmp(str0, str2, 2));

// 	printf("strncmp    : ABC: ABCD  = %d\n", strncmp(str0, str3, 2));
// 	printf("ft_strncmp : ABC: ABCD  = %d\n\n", strncmp(str0, str3, 2));

// 	printf("strncmp    : ABC: AB    = %d\n", strncmp(str0, str4, 2));
// 	printf("ft_strncmp : ABC: AB    = %d\n\n", ft_strncmp(str0, str4, 2));

// 	printf("strncmp    : ABC: B     = %d\n", strncmp(str0, str5, 2));
// 	printf("ft_strncmp : ABC: B     = %d\n\n", ft_strncmp(str0, str5, 2));

// 	printf("strncmp    : ABC: A     = %d\n", strncmp(str0, str6, 2));
// 	printf("ft_strncmp : ABC: A     = %d\n", ft_strncmp(str0, str6, 2));
// 	return (0);
// }