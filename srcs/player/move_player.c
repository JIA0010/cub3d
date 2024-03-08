/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:00:41 by hiraiyuina        #+#    #+#             */
/*   Updated: 2024/03/08 10:23:53 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define_ray.h"
#include "../../includes/player.h"

static bool	check_can_move(t_data *data, size_t x, size_t z);

int	player_move_w(t_data *data)
{
	printf("aaa\n");
	printf("x: %f, z: %f\n", data->player_pos->x, data->player_pos->z);
		// if (check_can_move(data, data->player_pos->x, data->player_pos->z - 1)
		// 	== true)
		// {
		// 	data->player_pos->x += (data->ray->p_dir_x / 5);
		// 	data->player_pos->z += (data->ray->p_dir_y / 5);
		// 	get_data_from_yhi(data->ray, data);
		// }
		return (1);
}

int	player_move_a(t_data *data)
{
	if (check_can_move(data, data->player_pos->x - 1,
			data->player_pos->z) == true)
	{
		printf("aaa\n");
		data->player_pos->x += (data->ray->p_dir_y / 5);
		data->player_pos->z -= (data->ray->p_dir_x / 5);
		get_data_from_yhi(data->ray, data);
	}
	return (1);
}

int	player_move_s(t_data *data)
{
	if (check_can_move(data, data->player_pos->x, data->player_pos->z
			+ 1) == true)
	{
		data->player_pos->x -= (data->ray->p_dir_x / 5);
		data->player_pos->z -= (data->ray->p_dir_y / 5);
		get_data_from_yhi(data->ray, data);
	}
	return (1);
}

int	player_move_d(t_data *data)
{
	if (check_can_move(data, data->player_pos->x + 1,
			data->player_pos->z) == true)
	{
		data->player_pos->x += (data->ray->p_dir_y / 5);
		data->player_pos->z += (data->ray->p_dir_x / 5);
		get_data_from_yhi(data->ray, data);
	}
	return (1);
}

static bool	check_can_move(t_data *data, size_t x, size_t z)
{
	printf("aaa\n");
	if (data->map->map[x][z] == '0')
		return (true);
	return (false);
}
