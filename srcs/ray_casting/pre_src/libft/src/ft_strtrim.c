/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:32:38 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:12:22 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t	find_start(char const *s, char const *set)
{
	size_t	start;

	start = 0;
	while (s[start] != '\0' && ft_strchr(set, s[start]) != NULL)
		start++;
	return (start);
}

static size_t	find_end(char const *s, size_t len, char const *set)
{
	size_t	end;

	end = len - 1;
	while (end > 0 && ft_strchr(set, s[end]) != NULL)
		end--;
	return (end);
}

static char	*trim_and_create_new_str(char const *s, size_t start, size_t end)
{
	size_t	new_len;
	char	*new_str;

	new_len = end - start + 1;
	new_str = (char *)malloc((new_len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, s + start, new_len);
	new_str[new_len] = '\0';
	return (new_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;
	char	*new_str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	start = find_start(s1, set);
	if (start == len)
	{
		new_str = (char *)malloc(1 * sizeof(char));
		if (new_str == NULL)
			return (NULL);
		new_str[0] = '\0';
		return (new_str);
	}
	end = find_end(s1, len, set);
	return (trim_and_create_new_str(s1, start, end));
}

// int	main(void)
// {
// 	char *str;
// 	char *result;

// 	str = "   aaa   b ";
// 	result = ft_strtrim(str, " ");
// 	printf("%s\n", result);
// }
