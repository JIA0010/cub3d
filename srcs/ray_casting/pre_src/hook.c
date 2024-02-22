/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:13:12 by cjia              #+#    #+#             */
/*   Updated: 2024/02/22 12:51:46 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define_ray.h"

int	close_window(t_ray *data)
{
	all_free(data->map);
	mlx_destroy_window(data->graphics_context, data->window);
	exit(0);
}

static int	key_hook(int keycode, t_ray *data)
{
	if (keycode == ESC)
		close_window(data);
	else if (keycode == W || keycode == UP)
		movement_player(data, 'w');
	else if (keycode == A || keycode == LEFT)
		movement_player(data, 'a');
	else if (keycode == S || keycode == DOWN)
		movement_player(data, 's');
	else if (keycode == D || keycode == RIGHT)
		movement_player(data, 'd');
	return (0);
}

void	hook(t_ray *data)
{
	mlx_hook(data->window, 2, 1L << 0, key_hook, data);
	mlx_hook(data->window, 17, 1L << 0, close_window, data);
}
