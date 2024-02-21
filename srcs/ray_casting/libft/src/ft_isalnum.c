/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:58:11 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:14:22 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

// int	ft_isalpha(int c)
// {
// 	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
// 		return (1);
// 	else
// 		return (0);
// }

// int	ft_isdigit(int c)
// {
// 	if (c >= '0' && c <= '9')
// 		return (1);
// 	else
// 		return (0);
// }

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) == 1 || ft_isalpha(c) == 1);
}

// int	ft_isalnum(int c)
// {
// 	return (ft_isdigit(c) == 1 || ft_isalpha(c) == 1)
// }

// int	main(void)
// {
// 	char str;

// 	str = '\0';

// 	printf("一文字入力せよ");
// 	scanf("%c", &str);
// 	printf("%d\n", ft_isalnum(str));
// 	return (0);
// }