/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:27:35 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/24 17:56:06 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/error.h"

static bool	check_map_closed(t_data *data);
static bool	inside(char **map, size_t x, size_t z);

bool	error_map(t_data *data)
{
	char	**map;
	size_t	x;
	size_t	z;

	map = data->map->map;
	z = 0;
	while (1)
	{
		x = 0;
		if (map[x][z] == '\0')
			break ;
		while (map[x] != NULL)
		{
			if (map[x][z] != '1' && map[x][z] != '0' && map[x][z] != 'N'
				&& map[x][z] != 'S' && map[x][z] != 'E' && map[x][z] != 'W'
				&& map[x][z] != ' ')
				return (false);
			x++;
		}
		z++;
	}
	if (check_map_closed(data) == false)
		return (false);
	return (true);
}

static bool	check_map_closed(t_data *data)
{
	size_t	x;
	size_t	z;

	z = 0;
	while (1)
	{
		x = 0;
		if (data->map->map[x][z] == '\0')
			break ;
		while (data->map->map[x] != NULL)
		{
			if (data->map->map[x][z] == '0'
				&& inside(data->map->map, x, z) == false)
				return (false);
			x++;
		}
		z++;
	}
	return (true);
}

static bool	inside(char **map, size_t x, size_t z)
{
	size_t	i;

	i = 0;
	while (map[x + i] != NULL && map[x + i][z] != '1')
		i++;
	if (map[x + i] == NULL)
		return (false);
	i = 0;
	while (0 <= x + i && map[x + i][z] != '1')
		i--;
	if (x + i < 0)
		return (false);
	i = 0;
	while (map[x][z + i] != '\0' && map[x][z + i] != '1')
		i++;
	if (map[x][z + i] == '\0')
		return (false);
	i = 0;
	while (0 <= z + i && map[x][z + i] != '1')
		i--;
	if (z + i < 0)
		return (false);
	return (true);
}
