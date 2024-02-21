/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:42:32 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:12:07 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + ('a' - 'A'));
	}
	return (c);
}

// int main(void)
// {
// 	int b = 'A';
// 	int a = ft_tolower(b);
// 	// /* 2 */ check(ft_tolower('A') == 'a'); showLeaks();
// 	// /* 4 */ check(ft_tolower('Z') == 'z'); showLeaks();
// 	printf("%d\n", a);

// 	return (0);
// }

// int main(void)
// {
// 	signal(SIGSEGV, sigsegv);
// 	title("ft_tolower\t: ")

// 	/* 1 */ check(ft_tolower('A' - 1) == 'A' - 1); showLeaks();
// 	/* 2 */ check(ft_tolower('A') == 'a'); showLeaks();
// 	/* 3 */ check(ft_tolower('Z' + 1) == 'Z' + 1); showLeaks();
// 	/* 4 */ check(ft_tolower('Z') == 'z'); showLeaks();
// 	write(1, "\n", 1);
// 	return (0);
// }