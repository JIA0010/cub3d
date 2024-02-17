/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:07:30 by yhirai            #+#    #+#             */
/*   Updated: 2023/06/30 18:32:43 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c -= 'a' - 'A';
	return (c);
}

// int	main(void)
// {
// 	char	s1;
// 	char	s2;

// 	s1 = 'a';
// 	s2 = 'a';
// 	printf("   %c\n", toupper(s1));
// 	printf("ft %c\n", ft_toupper(s2));
// 	return (0);
// }
