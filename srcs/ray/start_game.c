/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:43:44 by cjia              #+#    #+#             */
/*   Updated: 2024/02/27 15:13:29 by yoshimurahi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			buffer[y * data->size + x]
				= tmp.addr[y * data->size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

void	place_images_in_game(t_ray *data)
{
	int	x;
	int	y;

	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		clean_exit(data, err_msg(NULL, "Could not allocate memory", 1));
	data->textures[NORTH] = xpm_to_img(data, P_IMG_ITEM);
	data->textures[SOUTH] = xpm_to_img(data, P_IMG_ITEM);
	data->textures[EAST] = xpm_to_img(data, P_IMG_ITEM);
	data->textures[WEST] = xpm_to_img(data, P_IMG_ITEM);
}

bool	start_game(t_data *data_yhi)
{
	t_ray	data;

	init_data(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return(error("Failed to initialize graphics context"), false);
	data.win = mlx_new_window(data.mlx, WIN_WIDTH,
			WIN_HEIGHT, "cub3D");
	if (!data.win)
		return(error("Failed to create window"), false);

	place_images_in_game(&data);
	render_raycast(&data);
	// hook(data);
	mlx_loop(data.mlx);
	return (true);
}