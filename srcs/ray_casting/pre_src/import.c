/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:43:44 by cjia              #+#    #+#             */
/*   Updated: 2024/02/21 15:10:04 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define_ray.h"

void	import_map(char **argv, t_map *map)
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
void	start_game(t_ray data, t_map map)
{
	data.graphics_context = mlx_init();
	if (!data.graphics_context)
		error("Failed to initialize graphics context");
	data.window = mlx_new_window(data.graphics_context, data.map_width * 40,
			data.map_height * 40, "so_long");
	if (!data.window)
		error("Failed to create window");
	data = place_images_in_game(data);
	create_map(&data);
	hook(&data);
	mlx_loop(data.graphics_context);
}
