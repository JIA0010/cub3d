/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:46:04 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:14:17 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// int	main(void)
// {
// 	char ch = 'A';

// 	if (isascii(ch))
// 	{
// 		printf("%c = ASCII\n", ch);
// 	}
// 	else
// 	{
// 		printf("%c != ASCII\n", ch);
// 	}

// 	return (0);
// }