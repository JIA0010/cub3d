/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:43:44 by cjia              #+#    #+#             */
/*   Updated: 2024/03/18 09:55:32 by yoshimurahi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/define_ray.h"

static int	*xpm_to_img(t_ray *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * data->size * data->size);
	if (!buffer)
		clean_exit(data, err_msg(NULL, "Could not allocate memory", 1));
	y = 0;
	while (y < data->size)
	{
		x = 0;
		while (x < data->size)
		{
			buffer[y * data->size + x] = tmp.addr[y * data->size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

void	place_images_in_game(t_ray *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		clean_exit(data, err_msg(NULL, "Could not allocate memory", 1));
	data->textures[NORTH] = xpm_to_img(data, data->north);
	data->textures[SOUTH] = xpm_to_img(data, data->south);
	data->textures[EAST] = xpm_to_img(data, data->east);
	data->textures[WEST] = xpm_to_img(data, data->west);
}

static int	mouse_motion_handler(int x, int y, t_ray *data)
{
	static int	old_x = WIN_WIDTH / 2;

	(void)y;
	if (x == old_x)
		return (0);
	else if (x < old_x)
		rotate_player(data, -1);
	else if (x > old_x)
		rotate_player(data, 1);
	old_x = x;
	return (0);
}

bool	start_game(t_data *data_yhi)
{
	t_ray	data;

	init_data(&data, data_yhi);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (error("Failed to initialize graphics context"), false);
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data.win)
		return (error("Failed to create window"), false);
	place_images_in_game(&data);
	raycast_and_draw(&data);
	mlx_hook(data.win, 2, 1L << 0, key_event, &data);
	mlx_hook(data.win, 3, 1L << 0, key_release_hook, &data);
	mlx_hook(data.win, 17, 1L << 2, key_hook_esc, data_yhi);
	mlx_loop_hook(data.mlx, rotate_move, &data);
	mlx_hook(data.win, 6, 1L << 6, mouse_motion_handler, &data);
	mlx_loop(data.mlx);
	return (true);
}
