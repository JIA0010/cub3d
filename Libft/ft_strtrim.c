/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:55:16 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/30 16:07:02 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static int	is_set(char const s1, char const *set)
{
	size_t	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (s1 == set[j])
			return (1);
		else
			j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			len;
	size_t			s1len;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = 0;
	s1len = ft_strlen(s1);
	while (is_set(s1[start], set) == 1)
		start++;
	while (is_set(s1[s1len - 1], set) == 1)
		s1len--;
	len = s1len - start;
	return (ft_substr(s1, start, len));
}

// int	main(void)
// {
// 	char const	*s1;
// 	char const	*set;

// 	s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n 
//Trim me !\n   \n \n \t\t\n  ";
// 	set = " \n\t";
// 	printf("%s\n", ft_strtrim(s1, set));
// 	free(ft_strtrim(s1, set));
// 	return (0);
// }
