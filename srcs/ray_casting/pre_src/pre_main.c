/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:56:31 by cjia              #+#    #+#             */
/*   Updated: 2024/02/21 19:48:14 by yoshimurahi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define_ray.h"

void	init(t_ray *ray)
{
	printf("hello\n");
	ray->pos_x = 22;
	ray->pos_y = 12;
	ray->dir_x = -1;
	ray->dir_y = 0;
	ray->plane_x = 0;
	ray->plane_y = 0.66;
	ray->time = 0;
	ray->old_time = 0;
	ray->map_width = 0;
	ray->map_height = 0;
}

void	set_null(t_ray *data)
{
	int	tmp;
	int	i;
	int	j;

	tmp = data->map_height;
	i = 0;
	while (tmp--)
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
			j++;
		if (data->map[i][j] == '\n')
			data->map[i][j] = '\0';
		i++;
	}
	data->map[i] = NULL;
}

void	make_mapx_memory(t_ray *data)
{
	data->map = (char **)malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map)
		error("failed to get memory");
}

int	main(int argc, char **argv)
{
	int		i;
	t_ray	ray;

	i = 0;
	// ray = (t_ray *)malloc(sizeof(t_ray));
	// map = (t_map *)malloc(sizeof(t_map));
	init(&ray);
	if (argc != 2)
		error("Usage: ./cub3d <map_file>\n");
	import_map(argv, &ray);
	start_game(&ray);
}
// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q pre_ray_casting");
// }
