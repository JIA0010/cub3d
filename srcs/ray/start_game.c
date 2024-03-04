/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:43:44 by cjia              #+#    #+#             */
/*   Updated: 2024/03/04 16:48:32 by yoshimurahi      ###   ########.fr       */
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


static int	rotate_left_right(t_ray *data, double rotspeed)
{
	t_ray	*tmp;
	double		tmp_x;

	tmp = data;
	tmp_x = tmp->p_dir_x;
	tmp->p_dir_x = tmp->p_dir_x * cos(rotspeed) - tmp->p_dir_y * sin(rotspeed);
	tmp->p_dir_y = tmp_x * sin(rotspeed) + tmp->p_dir_y * cos(rotspeed);
	tmp_x = tmp->plane_x;
	tmp->plane_x = tmp->plane_x * cos(rotspeed) - tmp->plane_y * sin(rotspeed);
	tmp->plane_y = tmp_x * sin(rotspeed) + tmp->plane_y * cos(rotspeed);
	return (1);
}

int	rotate_player(t_ray *data, double rotdir)
{
	int		moved;
	double	rotspeed;

	moved = 0;
	rotspeed = ROTSPEED * rotdir;
	moved += rotate_left_right(data, rotspeed);
	return (moved);
}


int key_event(int key, t_ray *data)
{
	printf("key_event: %d\n", key);
	if(key == LEFT)
		data->rotate -= 1;
	else if(key == RIGHT)
		data->rotate += 1;
	return (0);
}

int key_release_hook(int key, t_ray *data)
{
	if (key == LEFT && data->rotate <= 1)
		data->rotate = 0;
	if (key == RIGHT && data->rotate >= -1)
		data->rotate = 0;
	return (0);
}


int	render(t_ray *data)
{
	int	moved;
	
	moved = 0;
	if (data->rotate != 0)
		moved += rotate_player(data, data->rotate);
	if(moved != 0)
		raycast_and_draw(data);
	return (0);
}

bool	start_game(t_data *data_yhi, char **av)
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
	printf("data->rotate: %d\n", data.rotate);
	mlx_hook(data.win, 2, 1L << 0, key_event, &data);
	mlx_hook(data.win, 3, 1L << 0, key_release_hook, &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (true);
}
