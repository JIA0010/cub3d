/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:39:04 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/30 15:29:40 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "libft.h"

static int	is_needle(char *str, const char *needle, size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (i < len && str[j] == needle[j] && str[j] != '\0')
	{
		i++;
		j++;
	}
	if (j == ft_strlen(needle))
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)haystack;
	if (needle[0] == '\0')
		return (str);
	while (i < len && *str != '\0')
	{
		if (*str == needle[0] && is_needle(str, needle, i, len) == 1)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*largestring = "";
// 	const char	*smallstring = "123456";
// 	char		*ptr;
// 	size_t		i;

// 	i = 10;
// 	ptr = strnstr(largestring, smallstring, i);
// 	printf("   %s\n", ptr);
// 	ptr = ft_strnstr(largestring, smallstring, i);
// 	printf("ft %s\n", ptr);

// 	// char haystack[30] = "aaabcabcd";
// 	// char needle[10] = "aabc";
// 	// printf("%s\n", strnstr(haystack, needle, -1));
// 	// printf("%s\n", ft_strnstr(haystack, needle, -1));

// 	return (0);
// }
