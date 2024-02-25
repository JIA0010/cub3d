/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:43:44 by cjia              #+#    #+#             */
/*   Updated: 2024/02/25 15:51:21 by yoshimurahi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define_ray.h"

void	place_images_in_game(t_ray *data)
{
	int	x;
	int	y;

	data->player = mlx_xpm_file_to_image(data->mlx, P_IMG_PLAYER,
			&x, &y);
	data->grass = mlx_xpm_file_to_image(data->mlx, P_IMG_GRASS, &x,
			&y);
	data->wood = mlx_xpm_file_to_image(data->mlx, P_IMG_WOOD, &x,
			&y);
	data->goal = mlx_xpm_file_to_image(data->mlx, P_IMG_GOAL, &x,
			&y);
	data->item = mlx_xpm_file_to_image(data->mlx, P_IMG_ITEM, &x,
			&y);
}

void	start_game(t_ray *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error("Failed to initialize graphics context");
	data->win = mlx_new_window(data->mlx, WIN_WIDTH,
			WIN_HEIGHT, "cub3D");
	if (!data->win)
		error("Failed to create window");
	place_images_in_game(data);
	render_raycast(data);
	hook(data);
	mlx_loop(data->mlx);
}
