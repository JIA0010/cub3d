/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:32:50 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/30 15:46:48 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

// static char	ft_function(unsigned int nb, char c)
// {
// 	if ('a' <= c && c <= 'z')
// 		c -= 32;
// 	printf("%d\n", nb);
// 	printf("%c\n", c);
// 	return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	char			*str;

	if (s == NULL || f == NULL)
		return (NULL);
	count = ft_strlen(s);
	str = malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	count = 0;
	while (s[count] != '\0')
	{
		str[count] = f(count, s[count]);
		count++;
	}
	str[count] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char	(*f)(unsigned int, char);
// 	char	*str;

// 	f = ft_function;
// 	str = ft_strmapi("abc", f);
// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }
