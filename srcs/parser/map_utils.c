/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:35:16 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/25 16:49:59 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

size_t	map_x_len(char *line)
{
	size_t	i;
	size_t	len;
	size_t	max;

	i = 0;
	len = 0;
	max = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			if (max < len)
				max = len;
			len = 0;
		}
		len++;
		i++;
	}
	return (max);
}

size_t	map_z_len(char *line)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (line[i] != '\0')
	{
		len++;
		i++;
		while (line[i] != '\0' && line[i] != '\n')
			i++;
	}
	return (len);
}
