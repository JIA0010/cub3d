/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:42:09 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/28 17:48:56 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	count;

	if (s == NULL)
		return (NULL);
	i = 0;
	count = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	while (count < len && s[count + start] != '\0')
		count++;
	str = malloc((sizeof(char)) * (count + 1));
	if (str == NULL)
		return (NULL);
	while (i < len && s[i + start] != '\0')
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char * s = ft_substr("tripouille", 100, 1);
// 	// char * s = ft_substr("tripouille", 11, 42000);
// 	printf("%s\n", s);
// 	// /* 2 */ mcheck(s, strlen("tripouille") + 1); free(s); showLeaks();

// 	// /* 5 */ check(!strcmp(s, ""));
// }
