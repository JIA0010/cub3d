/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:50:26 by yoshimurahi       #+#    #+#             */
/*   Updated: 2024/03/13 10:34:24 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/define_ray.h"
#include "../../includes/player.h"

static int	rotate_left_right(t_ray *data, double rotspeed)
{
	t_ray	*tmp;
	double	tmp_x;

	tmp = data;
	tmp_x = tmp->p_dir_x;
	tmp->p_dir_x = tmp->p_dir_x * cos(rotspeed) - tmp->p_dir_y * sin(rotspeed);
	tmp->p_dir_y = tmp_x * sin(rotspeed) + tmp->p_dir_y * cos(rotspeed);
	tmp_x = tmp->plane_x;
	tmp->plane_x = tmp->plane_x * cos(rotspeed) - tmp->plane_y * sin(rotspeed);
	tmp->plane_y = tmp_x * sin(rotspeed) + tmp->plane_y * cos(rotspeed);
	return (1);
}

int	rotate_player(t_ray *data, double rotdir)
{
	int		moved;
	double	rotspeed;

	moved = 0;
	rotspeed = ROTSPEED * rotdir;
	moved += rotate_left_right(data, rotspeed);
	return (moved);
}

int	key_event(int key, t_ray *data)
{
	if (key == LEFT)
		data->rotate = -1;
	else if (key == RIGHT)
		data->rotate = 1;
	if (key == W)
		data->move_y = 1;
	if (key == A)
		data->move_y = -1;
	if (key == S)
		data->move_x = -1;
	if (key == D)
		data->move_x = 1;
	else if (key == ESC)
		clean_exit(data, 0);
	return (0);
}

int	key_release_hook(int key, t_ray *data)
{
	if (key == LEFT && data->rotate == -1)
		data->rotate = 0;
	if (key == RIGHT && data->rotate == 1)
		data->rotate = 0;
	if (key == W && data->move_y == 1)
		data->move_y = 0;
	if (key == A && data->move_y == -1)
		data->move_y = 0;
	if (key == S && data->move_x == -1)
		data->move_x += 1;
	if (key == D && data->move_x == 1)
		data->move_x -= 1;
	return (0);
}

int	rotate_move(t_ray *data)
{
	int	moved;

	moved = 0;
	if (data->rotate != 0)
		moved += rotate_player(data, data->rotate);
	if (data->move_y == 1)
		moved += player_move_w(data->data);
	if (data->move_y == -1)
		moved += player_move_a(data->data);
	if (data->move_x == -1)
		moved += player_move_s(data->data);
	if (data->move_x == 1)
		moved += player_move_d(data->data);
	if (moved != 0)
		moved += raycast_and_draw(data);
	return (0);
}
