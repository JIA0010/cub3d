/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:59:21 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/23 18:30:47 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include "libft.h"

int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}

// int	main(void)
// {
// 	char	c;

// 	c = '	';
// 	printf("   %d\n", isprint(c));
// 	printf("ft %d\n", ft_isprint(c));
// 	return (0);
// }
