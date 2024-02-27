/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:42:11 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/27 16:54:36 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/define_ray.h"
#include "../includes/error.h"
#include "../includes/init.h"
#include "../includes/parser.h"
#include "../includes/player.h"

static void	test(t_data *data);

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
	test(data);
	if (start_game(data, argv) == false)
		return (ft_free(data), false);
	return (ft_free(data), true);
}

static void	test(t_data *data)
{
	size_t	x;
	size_t	z;

	printf("-----all-----\n%s\n-------------\n\n", data->parser->all);
	printf("path_north[%s]\n", data->parser->path_north);
	printf("path_south[%s]\n", data->parser->path_south);
	printf("path_west[%s]\n", data->parser->path_west);
	printf("path_east[%s]\n\n", data->parser->path_east);
	printf("floor_rgb[%d,%d,%d]\n", data->parser->floor_r,
			data->parser->floor_g, data->parser->floor_b);
	printf("ceiling_rgb[%d,%d,%d]\n\n", data->parser->ceiling_r,
			data->parser->ceiling_g, data->parser->ceiling_b);
	printf("-----map-----\n");
	z = 0;
	while (1)
	{
		x = 0;
		if (data->parser->map[x][z] == '\0')
			break ;
		while (data->parser->map[x] != NULL)
		{
			printf("%c", data->parser->map[x][z]);
			x++;
		}
		printf("\n");
		z++;
	}
	printf("-------------\n\n");
	printf("player [x = %ld, z = %ld]\n\n", data->player_pos->x,
			data->player_pos->z);
}

// __attribute__((destructor))
// static void	destructor(void)
// {
// 	system("leaks -q cub3d");
// }
