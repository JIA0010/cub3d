/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:52:26 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:12:58 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(char *src)
{
	int		len;
	char	*dest;
	char	*p;

	len = ft_strlen(src);
	p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	dest = p;
	while (*src != '\0')
	{
		*p = *src;
		src++;
		p++;
	}
	*p = '\0';
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *src;
// 	char *dest;

// 	src = "水曜日、もくようび";
// 	dest = ft_strdup(src);
// 	printf("src  : %s\n", src);
// 	printf("dest : %s\n", dest);
// 	return (0);
// }