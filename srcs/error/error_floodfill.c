/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_floodfill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:41:11 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/25 16:32:27 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/error.h"

static void	floodfill(t_data *data, bool *flag, size_t x, size_t z);

bool	error_floodfill(t_data *data)
{
	bool	flag;

	flag = true;
	floodfill(data, &flag, data->player_pos->x, data->player_pos->z);
	if (flag == false)
		return (printf("Map is not closed\n"), false);
	return (true);
}

static void	floodfill(t_data *data, bool *flag, size_t x, size_t z)
{
	if (data->map->map[x + 1] == NULL || data->map->map[x - 1] == NULL
		|| data->map->map[x + 1][z] == '\0' || data->map->map[x - 1][z] == '\0'
		|| data->map->map[x][z + 1] == '\0' || data->map->map[x][z - 1] == '\0'
		|| data->map->map[x + 1][z] == ' ' || data->map->map[x - 1][z] == ' '
		|| data->map->map[x][z + 1] == ' ' || data->map->map[x][z - 1] == ' ')
	{
		*flag = false;
		return ;
	}
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
