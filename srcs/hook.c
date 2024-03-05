/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:25:22 by yoshimurahi       #+#    #+#             */
/*   Updated: 2024/03/05 17:36:17 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define_ray.h"
#include "../includes/cub3d.h"
#include "../includes/player.h"


// void hook_events(t_ray *ray)
// {
//     mlx_hook(ray->win, 2, 1L << 0, key_press, ray);
//     mlx_hook(ray->win, 3, 1L << 1, key_release, ray);
//     mlx_hook(ray->win, 17, 1L << 17, close_win, ray);
// }

int	key_hook_esc(t_data *data)
{
	ft_free(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook(int key, t_data *data)
{
	// if (key == KEY_W || key == KEY_ARROW_U)
	// 	player_move_w(data);
	// if (key == KEY_A || key == KEY_ARROW_L)
	// 	player_move_a(data);
	// if (key == KEY_S || key == KEY_ARROW_D)
	// 	player_move_s(data);
	// if (key == KEY_D || key == KEY_ARROW_R)
	// 	player_move_d(data);
	if (key == KEY_ESC)
		key_hook_esc(data);
	return (0);
}