/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:52:17 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/29 19:34:50 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1)
		return (1);
	else if (ft_isdigit(c) == 1)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	char	c;

// 	c = 'a';
// 	printf("   %d\n", isalnum(c));
// 	printf("ft %d\n", ft_isalnum(c));
// 	return (0);
// }
