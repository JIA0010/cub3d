/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:43:44 by cjia              #+#    #+#             */
/*   Updated: 2024/03/08 13:00:34 by yhirai           ###   ########.fr       */
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
						sizeof *buffer * data->size * data->size);
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
	data->textures = ft_calloc(5, sizeof *data->textures);
	if (!data->textures)
		clean_exit(data, err_msg(NULL, "Could not allocate memory", 1));
	data->textures[NORTH] = xpm_to_img(data, data->north);
	data->textures[SOUTH] = xpm_to_img(data, data->south);
	data->textures[EAST] = xpm_to_img(data, data->east);
	data->textures[WEST] = xpm_to_img(data, data->west);
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
	// mlx_key_hook(data.win, key_hook, data_yhi);
	mlx_hook(data.win, 2, 1L << 0, key_event, &data);
	mlx_hook(data.win, 3, 1L << 0, key_release_hook, &data);
	// mlx_hook(data.win, 17, 1L << 2, key_hook_esc, data_yhi);
	mlx_loop_hook(data.mlx, rotate_move, &data);
	mlx_loop(data.mlx);
	return (true);
}
