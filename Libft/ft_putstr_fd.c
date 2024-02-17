/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:17:08 by yhirai            #+#    #+#             */
/*   Updated: 2023/06/02 14:03:34 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	count;

	if (s == NULL)
		return ;
	count = ft_strlen(s);
	write(fd, s, count);
}

// int	main(void)
// {
// 	char	*s;
// 	int	fd;
// 	fd = 1;
// 	s = "abcdefg";
// 	ft_putstr_fd(s, fd);
// }
