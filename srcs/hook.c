/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:25:22 by yoshimurahi       #+#    #+#             */
/*   Updated: 2024/03/12 16:29:10 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/define_ray.h"
#include "../includes/player.h"

int	key_hook_esc(t_data *data)
{
	ft_free(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook(int key, t_data *data)
{
	if (key == KEY_W)
		player_move_w(data);
	if (key == KEY_A)
		player_move_a(data);
	if (key == KEY_S)
		player_move_s(data);
	if (key == KEY_D)
		player_move_d(data);
	if (key == KEY_ESC)
		key_hook_esc(data);
	return (0);
}
