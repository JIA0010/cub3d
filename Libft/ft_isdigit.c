/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:11:07 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/29 19:20:09 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include "libft.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

// int	main(void)
// {
// 	char	c;

// 	c = '1';
// 	printf("   %d\n", isdigit(c));
// 	printf("ft %d\n", ft_isdigit(c));
// 	return (0);
// }
