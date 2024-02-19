/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:11:39 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/29 19:19:36 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

// int	main(void)
// {
// 	char str1[] = "0123456789";
// 	char str2[] = "0123456789";

// 	bzero(str1+2, 5);
// 	ft_bzero(str2+2, 5);
// 	printf("   %s\n",str1);
// 	printf("ft %s\n",str2);
// 	return (0);
// }
