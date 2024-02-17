/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:54:59 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/29 19:20:07 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

// int	main(void)
// {
// 	char	c;

// 	c = 'a';
// 	printf("   %d\n", isascii(c));
// 	printf("ft %d\n", ft_isascii(c));
// 	return (0);
// }
