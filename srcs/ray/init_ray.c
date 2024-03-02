/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:20:57 by yoshimurahi       #+#    #+#             */
/*   Updated: 2024/03/02 18:00:14 by yoshimurahi      ###   ########.fr       */
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

bool	init_floor_ceiling(t_ray *data, t_data *data_yhi)
{
	int	*rgb_ceiling;
	int	*rgb_floor;

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
	data->hex_ceiling = convert_rgb_to_hex(rgb_ceiling);
	data->hex_floor = convert_rgb_to_hex(rgb_floor);
	return (true);
}

void	init_texture_img(t_ray *data, t_img *image, char *path)
{
	init_img_clean(image);
	image->img = mlx_xpm_file_to_image(data->mlx, path, &data->size, &data->size);
	if (image->img == NULL)
		clean_exit(data, err_msg("mlx", "Could not create mlx image", 1));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	init_img_clean(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	init_texinfo(t_ray *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->floor = 0;
	textures->ceiling = 0;
	textures->hex_floor = 0x0;
	textures->hex_ceiling = 0x0;
	textures->size = TEX_SIZE;
	textures->step = 0.0;
	textures->pos = 0.0;
	textures->x1 = 0;
	textures->y1 = 0;
}

static void	init_mapinfo(t_ray *mapinfo)
{
	mapinfo->fd = 0;
	mapinfo->line_count = 0;
	mapinfo->path = NULL;
	mapinfo->file = NULL;
	mapinfo->map_height = 0;
	mapinfo->map_width = 0;
	mapinfo->index_end_of_map = 0;
}

static void	init_player(t_ray *player)
{
	player->dir = '\0';
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->p_dir_x = 0.0;
	player->p_dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->has_moved = 0;
	player->move_x = 0;
	player->move_y = 0;
	player->rotate = 0;
}

void	init_data(t_ray *data, t_data *data_yhi)
{
	data->mlx = NULL;
	data->win = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	init_player(data);
	init_texinfo(data);
	data->map = NULL;
	init_mapinfo(data);
	data->texture_pixels = NULL;
	data->textures = NULL;
	data->pos_x = data_yhi->player_pos->x;
	data->pos_y = data_yhi->player_pos->z;
	data->dir = data_yhi->player_pos->direction;
	data->map = data_yhi->map->map;
	data->map_height = data_yhi->map->map_hight;
	data->map_width = data_yhi->map->map_width;
	init_floor_ceiling(data, data_yhi);
	init_player_direction(data);
}
