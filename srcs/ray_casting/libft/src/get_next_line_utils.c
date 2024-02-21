/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:02:55 by cjia              #+#    #+#             */
/*   Updated: 2023/08/29 11:35:15 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	i = 0;
	src_len = ft_strlen(src);
	if (size != 0)
	{
		while (i < size - 1 && i < src_len)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	new_str_len;
	char	*new_str;

	new_str_len = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	new_str_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc((new_str_len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(new_str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (new_str);
}

void	*ft_calloc(size_t n, size_t size)
{
	size_t			total_size;
	void			*q;
	size_t			i;
	unsigned char	*p;

	if (size && n > SIZE_MAX / size)
		return (NULL);
	total_size = n * size;
	q = malloc(total_size);
	if (q == NULL)
		return (NULL);
	if (q != NULL)
	{
		i = 0;
		p = (unsigned char *)q;
		while (i < total_size)
		{
			p[i] = 0;
			i++;
		}
	}
	return (q);
}
