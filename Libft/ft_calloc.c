/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:15:36 by yhirai            #+#    #+#             */
/*   Updated: 2023/07/07 16:08:48 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	if (count == 0 || size == 0)
		return (ft_strdup(""));
	if (SIZE_MAX / size < count)
		return (NULL);
	ptr = malloc(size * count);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return ((void *)ptr);
}

// int	main(void)
// {
//    int *ptr,*p;
//    int i;
//    /* 500個のintサイズのメモリを確保 */
//    ptr = (int *)ft_calloc(500,sizeof(int));
//    if(ptr == NULL) {
//       printf("メモリが確保できません\n");
//       exit(EXIT_FAILURE);
//    }

//    p = ptr;
//    for (i=0; i<500; i++) {
//       *p = i;
//       printf("%d ",*p);
//       p++;
//    }

//    /* メモリの開放 */
//    free(ptr);
//    return 0;
// }
