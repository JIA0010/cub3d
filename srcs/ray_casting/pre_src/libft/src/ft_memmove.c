/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:58:51 by cjia              #+#    #+#             */
/*   Updated: 2023/06/02 13:12:44 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, void *src, int n)
{
	unsigned char	*c_dest;
	unsigned char	*c_src;

	c_dest = (unsigned char *)dest;
	c_src = (unsigned char *)src;
	if (c_dest == NULL && c_src == NULL)
		return (NULL);
	if (dest <= src)
	{
		while (n--)
			*c_dest++ = *c_src++;
	}
	else
	{
		c_dest += n;
		c_src += n;
		while (n--)
		{
			*(--c_dest) = *(--c_src);
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char	*src;
// 	char	*dst;

// 	src = malloc(100);
// 	for (int i = 0; i < 100; i++)
// 		src[i] = i;
// 	dst = malloc(100);
// 	ft_memmove(dst, src, 10);
// 	for (int i = 0; i < 10; i++)
// 		printf("%d ", dst[i]);
// 	printf("\n");
// 	free(src);
// 	free(dst);
// 	return (0);
// }
