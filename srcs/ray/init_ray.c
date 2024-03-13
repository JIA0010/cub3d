/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:35:42 by cjia              #+#    #+#             */
/*   Updated: 2024/03/13 10:36:59 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define_ray.h"

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
	textures->texture_pixels = NULL;
	textures->textures = NULL;
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->hex_floor = 0x0;
	textures->hex_ceiling = 0x0;
	textures->size = TEX_SIZE;
	textures->step = 0.0;
	textures->pos = 0.0;
	textures->x1 = 0;
	textures->y1 = 0;
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
	player->rotate = 0;
	player->move_x = 0;
	player->move_y = 0;
}

void	get_data_from_yhi(t_ray *data, t_data *data_yhi)
{
	data->data = data_yhi;
	data->map = NULL;
	data->map_height = 0;
	data->map_width = 0;
	data->pos_x = data_yhi->player_pos->x;
	data->pos_y = data_yhi->player_pos->z;
	data->dir = data_yhi->player_pos->direction;
	data->map = data_yhi->map->map;
	data->map_height = data_yhi->map->map_hight;
	data->map_width = data_yhi->map->map_width;
	data->north = data_yhi->map->path_north;
	data->south = data_yhi->map->path_south;
	data->west = data_yhi->map->path_west;
	data->east = data_yhi->map->path_east;
}

void	init_data(t_ray *data, t_data *data_yhi)
{
	data->mlx = NULL;
	data->win = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	init_player(data);
	init_texinfo(data);
	get_data_from_yhi(data, data_yhi);
	init_floor_ceiling(data, data_yhi);
	init_player_direction(data);
	data_yhi->ray = data;
}
