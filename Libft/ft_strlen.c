/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:02:29 by yhirai            #+#    #+#             */
/*   Updated: 2023/06/01 16:16:30 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;

// 	str1 = "acbABC123";
// 	str2 = "acbABC123";
// 	printf("   %lu\n", strlen(str1));
// 	printf("ft %lu\n", ft_strlen(str2));
// 	return (0);
// }
