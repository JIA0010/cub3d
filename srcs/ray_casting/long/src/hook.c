/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:37:35 by yoshimurahi       #+#    #+#             */
/*   Updated: 2023/08/30 17:47:49 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_game_data *data)
{
	all_free(data->game_map);
	mlx_destroy_window(data->graphics_context, data->window);
	exit(0);
}

static int	key_hook(int keycode, t_game_data *data)
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

void	hook(t_game_data *data)
{
	data->player_walk_count = 0;
	mlx_hook(data->window, 2, 1L << 0, key_hook, data);
	mlx_hook(data->window, 17, 1L << 0, close_window, data);
}
