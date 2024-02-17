/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:17:50 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/30 15:30:57 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}

// int	main(void)
// {
// 	char	c1;
// 	char	c2;

// 	c1 = 'a';
// 	c2 = 'a';
// 	printf("   %d\n", tolower(c1));
// 	printf("ft %d\n", ft_tolower(c2));
// 	return (0);
// }
