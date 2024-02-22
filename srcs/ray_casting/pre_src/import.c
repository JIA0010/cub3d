/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:43:44 by cjia              #+#    #+#             */
/*   Updated: 2024/02/22 12:49:25 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define_ray.h"
#include "minilibx/mlx.h"

void	import_map(char **argv, t_ray *map)
{
	int	fd;
	int	i;
	int	tmp;

	map_hight_and_width(argv, map);
	tmp = map->map_height;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("file is having something wrong");
	make_mapx_memory(map);
	i = 0;
	while (tmp--)
	{
		map->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	set_null(map);
}

void	place_images_in_game(t_ray *data)
{
	int	x;
	int	y;

	data->player = mlx_xpm_file_to_image(data->graphics_context, P_IMG_PLAYER, &x,
			&y);
	data->grass = mlx_xpm_file_to_image(data->graphics_context, P_IMG_GRASS, &x,
			&y);
	data->wood = mlx_xpm_file_to_image(data->graphics_context, P_IMG_WOOD, &x,
			&y);
	data->goal = mlx_xpm_file_to_image(data->graphics_context, P_IMG_GOAL, &x,
			&y);
	data->item = mlx_xpm_file_to_image(data->graphics_context, P_IMG_ITEM, &x,
			&y);
}


void	start_game(t_ray *data)
{
	data->graphics_context = mlx_init();
	if (!data->graphics_context)
		error("Failed to initialize graphics context");
	data->window = mlx_new_window(data->graphics_context, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data->window)
		error("Failed to create window");
	place_images_in_game(data);
	create_map(data);
	// ray_casting(data);
	hook(data);
	mlx_loop(data->graphics_context);
}
