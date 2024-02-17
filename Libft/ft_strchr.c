/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:17:36 by yhirai            #+#    #+#             */
/*   Updated: 2023/06/02 16:55:31 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	size_t	i;

	ch = (char)c;
	i = 0;
	while (*s != '\0')
	{
		if (s[i] == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

// int	main(void)
// {
// 	char str[] = "", *p;
// 	int	c;

// 	c = 'a';
// 	p = strchr(str, c);
// 	if (p != NULL)
// 	{
// 		printf("%cは文字列の%ld番目にあります。\n", c, p-str);
// 		printf("以降の文字列は%sです。\n", p);
// 	}
// 	else
// 		printf("%cは見つかりませんでした\n", c);
// 	c = 'a';
// 	p = ft_strchr(str, c);
// 	if (p != NULL)
// 	{
// 		printf("%cは文字列の%ld番目にあります。\n", c, p-str);
// 		printf("以降の文字列は%sです。\n", p);
// 	}
// 	else
// 		printf("%cは見つかりませんでした\n", c);
// 	return (0);
// }
