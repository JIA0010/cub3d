/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:02:48 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:14:07 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, unsigned long n)
{
	unsigned char	*s;
	unsigned char	*m;

	s = (unsigned char *)buf1;
	m = (unsigned char *)buf2;
	while (n--)
	{
		if (*s != *m)
			return ((int)*s - (int)*m);
		s++;
		m++;
	}
	return (0);
}

// int main(void)
// {
// 	char s[] = {-128, 0, 127, 0};
// 	char sCpy[] = {-128, 0, 127, 0};
// 	char s2[] = {0, 0, 127, 0};
// 	char s3[] = {0, 0, 42, 0};
// 	int a = ft_memcmp(s2, s, 1);
// 	printf("%d\n", a);
// 	return (0);
// }

// int	main(void)
// {
// 	char str1[] = "Hello";
// 	char str2[] = "Hello";
// 	char str3[] = "World";

// 	if (ft_memcmp(str1, str2, sizeof(str1)) == 0)
// 	{
// 		printf("str1とstr2は同じ\n");
// 	}
// 	else
// 	{
// 		printf("str1とstr2は違う\n");
// 	}

// 	if (ft_memcmp(str1, str3, sizeof(str1)) == 0)
// 	{
// 		printf("str1とstr3は同じ\n");
// 	}
// 	else
// 	{
// 		printf("str1とstr3は違う\n");
// 	}

// 	return (0);
// }