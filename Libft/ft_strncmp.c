/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:47:05 by yhirai            #+#    #+#             */
/*   Updated: 2023/05/26 16:23:39 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	i = 0;
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	if (!n)
		return (0);
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (i < n && (s22[i] != '\0' || s11[i] != '\0'))
	{
		if (s11[i] != s22[i])
			return (s11[i] - s22[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char *s1 = "";
// 	char *s2 = "AAAAAA";
// 	int i1 = ((strncmp(s1, s2, 6) > 0) ? 1 : 
//((strncmp(s1, s2, 6) < 0) ? -1 : 0));
// 	int i2 = ((ft_strncmp(s1, s2, 6) > 0) ? 1 : 
//((ft_strncmp(s1, s2, 6) < 0) ? -1 : 0));
// 	printf("   %d\nft %d\n", i1, i2);
// }
