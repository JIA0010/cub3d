/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:43:44 by cjia              #+#    #+#             */
/*   Updated: 2024/02/28 17:30:02 by yoshimurahi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define_ray.h"

static unsigned long	convert_rgb_to_hex(int *rgb_tab)
{
	unsigned long	result;
	int				r;
	int				g;
	int				b;

	r = rgb_tab[0];
	g = rgb_tab[1];
	b = rgb_tab[2];
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (result);
}

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
	int	x;
	int	y;

	data->textures = ft_calloc(5, sizeof *data->textures);
	if (!data->textures)
		clean_exit(data, err_msg(NULL, "Could not allocate memory", 1));
	data->textures[NORTH] = xpm_to_img(data, P_IMG_ITEM);
	data->textures[SOUTH] = xpm_to_img(data, P_IMG_ITEM);
	data->textures[EAST] = xpm_to_img(data, P_IMG_ITEM);
	data->textures[WEST] = xpm_to_img(data, P_IMG_ITEM);
}

bool	start_game(t_data *data_yhi, char **av)
{
	t_ray	data;
	int  	*rgb_ceiling;
	int 	*rgb_floor;

	init_data(&data);
	data.pos_x = data_yhi->player_pos->x;
	data.pos_y = data_yhi->player_pos->z;
	data.dir = data_yhi->player_pos->direction;
	data.map = data_yhi->map->map;
	data.height = data_yhi->map->map_hight;
	data.width = data_yhi->map->map_width;

	rgb_floor = malloc(sizeof(int) * 3);
	if (!rgb_floor)
		return (error("Failed to allocate memory"), false);
	rgb_floor[0] = data_yhi->map->floor_r;
	rgb_floor[1] = data_yhi->map->floor_g;
	rgb_floor[2] = data_yhi->map->floor_b;

	rgb_ceiling = malloc(sizeof(int) * 3);
	if (!rgb_ceiling)
		return (error("Failed to allocate memory"), false);
	rgb_ceiling[0] = data_yhi->map->ceiling_r;
	rgb_ceiling[1] = data_yhi->map->ceiling_g;
	rgb_ceiling[2] = data_yhi->map->ceiling_b;
	
	data.hex_ceiling = convert_rgb_to_hex(rgb_ceiling);
	data.hex_floor = convert_rgb_to_hex(rgb_floor);
	init_player_direction(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (error("Failed to initialize graphics context"), false);
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data.win)
		return (error("Failed to create window"), false);
	place_images_in_game(&data);
	data.win_width = WIN_WIDTH;
	data.win_height = WIN_HEIGHT;
	raycast_and_draw(&data);
	// hook(data);
	mlx_loop(data.mlx);
	return (true);
}
