/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:14:29 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:14:27 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_bzero(void *str, int n)
{
	int				i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)str;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

// int	main(void)
// {
// 	char	str;

// 	str[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
// 	ft_bzero(*str, 5);
// 	printf("%c\n", str);
// 	return (0);
// }
