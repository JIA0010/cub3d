/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:27:35 by yhirai            #+#    #+#             */
/*   Updated: 2024/03/08 15:17:34 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/error.h"

bool	error_map(t_data *data)
{
	char	**map;
	size_t	x;
	size_t	z;

	map = data->map->map;
	x = 0;
	while (map[x] != NULL)
	{
		z = 0;
		while (map[x][z] != '\0')
		{
			if (map[x][z] != '1' && map[x][z] != '0' && map[x][z] != 'N'
				&& map[x][z] != 'S' && map[x][z] != 'E' && map[x][z] != 'W'
				&& map[x][z] != ' ' && map[x][z] != '\n' && map[x][z] != '\0')
				return (false);
			z++;
		}
		x++;
	}
	return (true);
}
