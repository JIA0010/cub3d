/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:55:05 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:13:48 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memset(void *str, int c, int num)
{
	int				i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)str;
	while (i < num)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	char str[10] = "igoooooons";
// 	int size = sizeof(str);

// 	ft_memset(str, 'A', sizeof(str) - 1); // strを文字'A'で埋める
// 	str[size - 1] = '\0';                 // 終端文字を追加する

// 	printf("str: %s\n", str); // 出力: str: AAAAAAAA

// 	return (0);
// }