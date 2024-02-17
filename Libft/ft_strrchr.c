/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:29:15 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/30 16:04:54 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*a;

	a = NULL;
	ch = (char)c;
	while (*s != '\0')
	{
		if (*s == ch)
			a = (char *)s;
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (a);
}

// int	main(void)
// {
// 	char str[] = "", *p;
// 	int	c;

// 	c = '\0';
// 	p = strrchr(str, c);
// 	if (p != NULL)
// 	{
// 		printf("%cは文字列の%ld番目にあります。\n", c, p-str);
// 		printf("以降の文字列は%sです。\n", p);
// 	}
// 	else
// 		printf("%cは見つかりませんでした\n", c);
// 	c = '\0';
// 	p = ft_strrchr(str, c);
// 	if (p != NULL)
// 	{
// 		printf("%cは文字列の%ld番目にあります。\n", c, p-str);
// 		printf("以降の文字列は%sです。\n", p);
// 	}
// 	else
// 		printf("%cは見つかりませんでした\n", c);
// 	return (0);
// }
