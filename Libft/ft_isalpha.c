/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:00:26 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/29 19:20:04 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include "libft.h"

int	ft_isalpha(int c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

// int	main(void)
// {
// 	char	c;

// 	c = ' ';
// 	printf("   %d\n", isalpha(c));
// 	printf("ft %d\n", ft_isalpha(c));
// 	return (0);
// }
