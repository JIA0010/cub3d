/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:45:45 by yhirai            #+#    #+#             */
/*   Updated: 2024/03/05 17:27:38 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"
#include "../../includes/define_ray.h"

static bool	check_can_move(t_data *data, size_t x, size_t z);

void	player_move_w(t_data *data)
{
	t_ray	ray;

	if (check_can_move(data, data->player_pos->x, data->player_pos->z - 1) == true)
		data->player_pos->z -= 1;
	init_data(&ray, data);
	place_images_in_game(&ray);
	raycast_and_draw(&ray);
}

void	player_move_a(t_data *data)
{
	if (check_can_move(data, data->player_pos->x - 1, data->player_pos->z) == true)
		data->player_pos->x -= 1;
}

void	player_move_s(t_data *data)
{
	if (check_can_move(data, data->player_pos->x, data->player_pos->z + 1) == true)
		data->player_pos->z += 1;
}

void	player_move_d(t_data *data)
{
	if (check_can_move(data, data->player_pos->x + 1, data->player_pos->z) == true)
		data->player_pos->x += 1;
}

static bool	check_can_move(t_data *data, size_t x, size_t z)
{
	if (data->map->map[x][z] == '0')
		return (true);
	return (false);
}
