/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:25:22 by yoshimurahi       #+#    #+#             */
/*   Updated: 2024/03/18 10:08:06 by yoshimurahi      ###   ########.fr       */
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
	// mlx_destroy_window(data->ray->mlx, data->ray->win);
	// mlx_destroy_image(data->ray->mlx, data->ray->texture_pixels[0]);
	// mlx_destroy_image(data->ray->mlx, data->ray->texture_pixels[1]);
	// mlx_destroy_image(data->ray->mlx, data->ray->texture_pixels[2]);
	// mlx_destroy_image(data->ray->mlx, data->ray->texture_pixels[3]);

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
