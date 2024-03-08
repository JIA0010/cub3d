/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:00:41 by hiraiyuina        #+#    #+#             */
/*   Updated: 2024/03/08 12:11:20 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define_ray.h"
#include "../../includes/player.h"

static bool	check_can_move(t_data *data, double x, double z);

bool	player_move_w(t_data *data)
{
	double	x;
	double	z;

	x = data->player_pos->x + (data->ray->p_dir_x / ONE_STEP);
	z = data->player_pos->z + (data->ray->p_dir_y / ONE_STEP);
	if (check_can_move(data, x, z) == true)
	{
		data->player_pos->x += (data->ray->p_dir_x / ONE_STEP);
		data->player_pos->z += (data->ray->p_dir_y / ONE_STEP);
		get_data_from_yhi(data->ray, data);
	}
	return (1);
}

bool	player_move_a(t_data *data)
{
	double	x;
	double	z;

	x = data->player_pos->x + (data->ray->p_dir_y / ONE_STEP);
	z = data->player_pos->z - (data->ray->p_dir_x / ONE_STEP);
	if (check_can_move(data, x, z) == true)
	{
		data->player_pos->x += (data->ray->p_dir_y / ONE_STEP);
		data->player_pos->z -= (data->ray->p_dir_x / ONE_STEP);
		get_data_from_yhi(data->ray, data);
		return (true);
	}
	return (false);
}

bool	player_move_s(t_data *data)
{
	double	x;
	double	z;

	x = data->player_pos->x - (data->ray->p_dir_x / ONE_STEP);
	z = data->player_pos->z - (data->ray->p_dir_y / ONE_STEP);
	if (check_can_move(data, x, z) == true)
	{
		data->player_pos->x -= (data->ray->p_dir_x / ONE_STEP);
		data->player_pos->z -= (data->ray->p_dir_y / ONE_STEP);
		get_data_from_yhi(data->ray, data);
		return (true);
	}
	return (false);
}

bool	player_move_d(t_data *data)
{
	double	x;
	double	z;

	x = data->player_pos->x + (data->ray->p_dir_y / ONE_STEP);
	z = data->player_pos->z + (data->ray->p_dir_x / ONE_STEP);
	if (check_can_move(data, x, z) == true)
	{
		data->player_pos->x += (data->ray->p_dir_y / ONE_STEP);
		data->player_pos->z += (data->ray->p_dir_x / ONE_STEP);
		get_data_from_yhi(data->ray, data);
		return (true);
	}
	return (false);
}

static bool	check_can_move(t_data *data, double x, double z)
{
	int	pos_x;
	int	pos_z;

	pos_x = (int)x;
	pos_z = (int)z;
	if (data->map->map[pos_x][pos_z] == '0')
		return (true);
	return (false);
}
