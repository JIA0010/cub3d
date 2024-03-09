/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:42:11 by yhirai            #+#    #+#             */
/*   Updated: 2024/03/09 15:26:51 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/define_ray.h"
#include "../includes/error.h"
#include "../includes/init.h"
#include "../includes/parser.h"
#include "../includes/player.h"

// static void	test(t_data *data);

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_error_arg(argc, argv) == false)
		return (false);
	data = init();
	if (data == NULL)
		return (ft_free(data), false);
	if (parser(data, argv[1]) == false)
		return (ft_free(data), false);
	if (player_pos(data) == false)
		return (ft_free(data), false);
	if (error_floodfill(data) == false)
		return (ft_free(data), false);
	// test(data);
	start_game(data);
	return (ft_free(data), true);
}

static void	test(t_data *data)
{
	size_t	x;
	size_t	z;

	printf("-----all-----\n%s\n-------------\n\n", data->map->all);
	printf("path_north[%s]\n", data->map->path_north);
	printf("path_south[%s]\n", data->map->path_south);
	printf("path_west[%s]\n", data->map->path_west);
	printf("path_east[%s]\n\n", data->map->path_east);
	printf("floor_rgb[%d,%d,%d]\n", data->map->floor_r,
		data->map->floor_g, data->map->floor_b);
	printf("ceiling_rgb[%d,%d,%d]\n\n", data->map->ceiling_r,
		data->map->ceiling_g, data->map->ceiling_b);
	printf("-----map-----\n");
	z = 0;
	while (1)
	{
		x = 0;
		if (data->map->map[x][z] == '\0')
			break ;
		while (data->map->map[x] != NULL)
		{
			printf("%c", data->map->map[x][z]);
			x++;
		}
		printf("\n");
		z++;
	}
	printf("-------------\n\n");
	printf("player [x = %f, z = %f]\n\n", data->player_pos->x, data->player_pos->z);
}

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q cub3d");
}
