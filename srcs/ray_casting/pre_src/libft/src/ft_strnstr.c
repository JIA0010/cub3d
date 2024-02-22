/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:28:31 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:12:29 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	substr_len;
	size_t	j;
	size_t	i;

	substr_len = ft_strlen(substr);
	if (*substr == '\0')
		return ((char *)str);
	else if (str == NULL && len == 0)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (j < substr_len && str[i + j] == substr[j] && (i + j) < len)
			j++;
		if (j == substr_len)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*str2;

// 	str = "libft-test-tokyo";
// 	str2 = NULL;
// 	printf("%s\n", strnstr(str2, str, 0));
// 	printf("%s\n", ft_strnstr(str2, str, 0));
// 	return (0);
// }
