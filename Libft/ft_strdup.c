/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:41:08 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/26 16:23:15 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		strlen;
	int		i;
	char	*s;

	s = (char *)s1;
	strlen = ft_strlen(s);
	i = 0;
	str = malloc(sizeof(char) * (strlen + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*str1;
// 	char	*str2;

// 	s1 = "abcdefg";
// 	str1 = strdup(s1);
// 	str2 = ft_strdup(s1);
// 	printf("   %s\n", str1);
// 	printf("ft %s\n", str2);
// 	free(str1);
// 	free(str2);
// 	return (0);
// }
