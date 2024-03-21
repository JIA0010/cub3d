/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_floodfill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:41:11 by yhirai            #+#    #+#             */
/*   Updated: 2024/03/21 19:15:11 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/error.h"

static void	floodfill(t_data *data, bool *flag, size_t x, size_t z);
static bool	check(t_data *data, bool *flag, size_t x, size_t z);
static void	fix_map(t_data *data);

bool	error_floodfill(t_data *data)
{
	bool	flag;

	flag = true;
	floodfill(data, &flag, data->player_pos->x, data->player_pos->z);
	if (flag == false)
		return (printf("Error\nMap is not closed\n"), false);
	fix_map(data);
	return (true);
}

static void	floodfill(t_data *data, bool *flag, size_t x, size_t z)
{
	if (check(data, flag, x, z) == false)
		return ;
	if (data->map->map[x + 1][z] == '0')
	{
		data->map->map[x + 1][z] = '*';
		floodfill(data, flag, x + 1, z);
	}
	if (data->map->map[x - 1][z] == '0')
	{
		data->map->map[x - 1][z] = '*';
		floodfill(data, flag, x - 1, z);
	}
	if (data->map->map[x][z + 1] == '0')
	{
		data->map->map[x][z + 1] = '*';
		floodfill(data, flag, x, z + 1);
	}
	if (data->map->map[x][z - 1] == '0')
	{
		data->map->map[x][z - 1] = '*';
		floodfill(data, flag, x, z - 1);
	}
}

static bool	check(t_data *data, bool *flag, size_t x, size_t z)
{
	if (x == 0 || z == 0
		|| data->map->map[x + 1] == NULL
		|| data->map->map[x + 1][z] == '\0'
		|| data->map->map[x - 1][z] == '\0'
		|| data->map->map[x][z + 1] == '\0'
		|| data->map->map[x][z - 1] == '\0'
		|| data->map->map[x + 1][z] == ' ' || data->map->map[x - 1][z] == ' '
		|| data->map->map[x][z + 1] == ' ' || data->map->map[x][z - 1] == ' ')
	{
		*flag = false;
		return (false);
	}
	return (true);
}

static void	fix_map(t_data *data)
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
			if (data->map->map[x][z] == '*')
				data->map->map[x][z] = '0';
			if (data->map->map[x][z] == 'N' || data->map->map[x][z] == 'S'
				|| data->map->map[x][z] == 'W' || data->map->map[x][z] == 'E')
				data->map->map[x][z] = '0';
			x++;
		}
		z++;
	}
}
