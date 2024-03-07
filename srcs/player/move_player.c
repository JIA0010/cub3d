/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:00:41 by hiraiyuina        #+#    #+#             */
/*   Updated: 2024/03/07 15:35:34 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"
#include "../../includes/define_ray.h"

static bool	check_can_move(t_data *data, size_t x, size_t z);

void	player_move_w(t_data *data)
{
	if (check_can_move(data, data->player_pos->x, data->player_pos->z - 1)
		== true)
	{
		data->map->map[data->player_pos->x][data->player_pos->z] = '0';
		data->player_pos->z -= 1;
		data->map->map[data->player_pos->x][data->player_pos->z] = 'P';
		get_data_from_yhi(data->ray, data);
		raycast_and_draw(data->ray);
	}
}

void	player_move_a(t_data *data)
{
	if (check_can_move(data, data->player_pos->x - 1, data->player_pos->z)
		== true)
	{
		data->map->map[data->player_pos->x][data->player_pos->z] = '0';
		data->player_pos->x -= 1;
		data->map->map[data->player_pos->x][data->player_pos->z] = 'P';
		get_data_from_yhi(data->ray, data);
		raycast_and_draw(data->ray);
	}
}

void	player_move_s(t_data *data)
{
	if (check_can_move(data, data->player_pos->x, data->player_pos->z + 1)
		== true)
	{
		data->map->map[data->player_pos->x][data->player_pos->z] = '0';
		data->player_pos->z += 1;
		data->map->map[data->player_pos->x][data->player_pos->z] = 'P';
		get_data_from_yhi(data->ray, data);
		raycast_and_draw(data->ray);
	}
}

void	player_move_d(t_data *data)
{
	if (check_can_move(data, data->player_pos->x + 1, data->player_pos->z)
		== true)
	{
		data->map->map[data->player_pos->x][data->player_pos->z] = '0';
		data->player_pos->x += 1;
		data->map->map[data->player_pos->x][data->player_pos->z] = 'P';
		get_data_from_yhi(data->ray, data);
		raycast_and_draw(data->ray);
	}
}

static bool	check_can_move(t_data *data, size_t x, size_t z)
{
	if (data->map->map[x][z] == '0')
		return (true);
	return (false);
}
