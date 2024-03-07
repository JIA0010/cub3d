/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:50:26 by yoshimurahi       #+#    #+#             */
/*   Updated: 2024/03/07 13:14:37 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define_ray.h"

static int	rotate_left_right(t_ray *data, double rotspeed)
{
	t_ray	*tmp;
	double		tmp_x;

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


int key_event(int key, t_ray *data)
{
	if(key == LEFT)
		data->rotate -= 1;
	else if(key == RIGHT)
		data->rotate += 1;
	else if(key == ESC)
		clean_exit(data, 0);
	return (0);
}

int key_release_hook(int key, t_ray *data)
{
	if (key == LEFT && data->rotate <= 1)
		data->rotate = 0;
	if (key == RIGHT && data->rotate >= -1)
		data->rotate = 0;
	return (0);
}


int	rotate(t_ray *data)
{
	int	moved;

	moved = 0;
	if (data->rotate != 0)
		moved += rotate_player(data, data->rotate);
	if(moved != 0)
		raycast_and_draw(data);
	return (0);
}
